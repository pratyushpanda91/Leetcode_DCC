#pragma clang attribute push([[clang::no_sanitize("address","thread","memory","undefined","coverage"), gnu::target("avx2,bmi2,fma,sse4a,tune=znver3")]], apply_to=any(function))

#include <sys/mman.h>
#include <x86intrin.h>

void preallocate(char* buffer, size_t size) noexcept {
    constexpr size_t kPageSize = 4096;
    for (char* ptr = buffer; ptr < buffer + size; ptr += kPageSize) {
        *ptr = 0;
    }
}

template<size_t kPoolSize, size_t kPrealocSize>
class HugePagePool {
public:
    HugePagePool() noexcept {
        constexpr size_t kHugePageSize = 2 << 20;
        buffer = static_cast<char*>(::operator new(kPoolSize, align_val_t{ kHugePageSize }));
        if (madvise(buffer, kPoolSize, MADV_HUGEPAGE) == -1) {
            cout << "madvise() failed: " << strerror(errno) << "\n";
        }
        preallocate(buffer, kPrealocSize);
    }
    [[clang::always_inline]]
    void* allocate(size_t size, size_t alignment) noexcept {
        auto block = __builtin_align_up(buffer, alignment);
        buffer = block + size;
        return block;
    }
private:
    friend class MemoryPoolScope;
    char* buffer = nullptr;
};

HugePagePool<1 << 30, 1 << 24> memory_pool;

class MemoryPoolScope {
public:
    MemoryPoolScope() noexcept : mark(memory_pool.buffer) {
    }
    ~MemoryPoolScope() {
        memory_pool.buffer = mark;
    }
private:
    char* mark;
};

template <class T>
[[nodiscard]]
T* pool_allocate(size_t n) noexcept {
    return static_cast<T*>(memory_pool.allocate(n * sizeof(T), alignof(T)));
}

template <class T, size_t align>
[[nodiscard]]
T* pool_allocate(size_t n) noexcept {
    return static_cast<T*>(memory_pool.allocate(__builtin_align_up(n * sizeof(T), align), align));
}

template <class T>
[[clang::always_inline]]
void set_max(T& a, T b) {
    a = a < b ? b : a;
}

template <class T>
[[clang::always_inline]]
T get_max(const T a, const T b) {
    return a < b ? b : a;
}

template <class T>
[[clang::always_inline]]
void interchange(T& a, T& b) {
    auto t = a;
    a = b;
    b = t;
}

const auto kAvxAlign = alignof(__m256i);

template <class T>
[[clang::always_inline]]
void avx_zeromem(T* data, size_t size) {
    auto p = reinterpret_cast<__m256i*>(data);
    const auto count = __builtin_align_up(size * sizeof(T), kAvxAlign) / kAvxAlign;
    for (size_t i = count - 1; i < count; --i) {
        _mm256_storeu_si256(p + i, _mm256_setzero_si256());
    }
}

template <class T>
[[clang::always_inline]]
void avx_copymem(T* dst, const T* src, size_t size) {
    auto d = reinterpret_cast<__m256i*>(dst);
    const auto s = reinterpret_cast<const __m256i*>(src);
    const auto count = __builtin_align_up(size * sizeof(T), kAvxAlign) / kAvxAlign;
    for (size_t i = 0; i < count; ++i) {
        _mm256_storeu_si256(d + i, _mm256_loadu_si256(s + i));
    }
}

int maxProfitImpl(uint32_t n, const int32_t* present, const int32_t* future, const uint32_t* const* g, int32_t budget) noexcept {
    auto reverse_topo_order = pool_allocate<uint32_t>(n);
    size_t ordered_idx = 0;
    auto dfs = [&](this auto&& dfs, uint32_t u) -> void {
        for (auto v = g[u]; v != g[u + 1]; ++v) {
            dfs(*v);
        }
        reverse_topo_order[ordered_idx++] = u;
    };
    dfs(0);
    struct S {
        int32_t* profit_no_discount;
        int32_t* profit_with_discount;
    };
    auto dp = pool_allocate<S>(n);
    auto tmp = pool_allocate<int32_t, kAvxAlign>(budget + 1);
    auto merged_no_discount = pool_allocate<int32_t, kAvxAlign>(budget + 1);
    auto merged_with_discount = pool_allocate<int32_t, kAvxAlign>(budget + 1);
    for (size_t i = 0; i < n; ++i) {
        const auto u = reverse_topo_order[i];
        dp[u].profit_no_discount = pool_allocate<int32_t, kAvxAlign>(budget + 1);
        dp[u].profit_with_discount = pool_allocate<int32_t, kAvxAlign>(budget + 1);
        switch (const auto chld_cnt = g[u + 1] - g[u]; chld_cnt) {
            case 0: {
                auto cost = present[u];
                auto p = get_max(future[u] - cost, 0);
                avx_zeromem(dp[u].profit_no_discount, cost);
                for (size_t b = cost; b <= budget; ++b) {
                    dp[u].profit_no_discount[b] = p;
                }
                cost >>= 1;
                p = get_max(future[u] - cost, 0);
                avx_zeromem(dp[u].profit_with_discount, cost);
                for (size_t b = cost; b <= budget; ++b) {
                    dp[u].profit_with_discount[b] = p;
                }
                break;
            }
            case 1: {
                const auto v = g[u][0];
                auto cost = present[u];
                for (size_t b = 0; b < cost; ++b) {
                    dp[u].profit_no_discount[b] = dp[v].profit_no_discount[b];
                }
                for (size_t b = cost; b <= budget; ++b) {
                    dp[u].profit_no_discount[b] = get_max(dp[v].profit_no_discount[b], future[u] - cost + dp[v].profit_with_discount[b - cost]);
                }
                cost >>= 1;
                for (size_t b = 0; b < cost; ++b) {
                    dp[u].profit_with_discount[b] = dp[v].profit_no_discount[b];
                }
                for (size_t b = cost; b <= budget; ++b) {
                    dp[u].profit_with_discount[b] = get_max(dp[v].profit_no_discount[b], future[u] - cost + dp[v].profit_with_discount[b - cost]);
                }
                break;
            }
            default: {
                const auto v0 = g[u][0];
                avx_copymem(merged_no_discount, dp[v0].profit_no_discount, budget + 1);
                avx_copymem(merged_with_discount, dp[v0].profit_with_discount, budget + 1);
                auto merge = [&][[clang::always_inline]](int32_t*& dst, const int32_t* src) {
                    __builtin_assume_separate_storage(dst, src);
                    avx_zeromem(tmp, budget + 1);
                    for (size_t i = 0; i <= budget; ++i) {
                        for (size_t j = 0; j <= budget - i; ++j) {
                            set_max(tmp[i + j], src[i] + dst[j]);
                        }
                    }
                    interchange(tmp, dst);
                };
                for (auto v = g[u] + 1; v != g[u + 1]; ++v) {
                    merge(merged_no_discount, dp[*v].profit_no_discount);
                    merge(merged_with_discount, dp[*v].profit_with_discount);
                }
                auto cost = present[u];
                for (size_t b = 0; b < cost; ++b) {
                    dp[u].profit_no_discount[b] = merged_no_discount[b];
                }
                for (size_t b = cost; b <= budget; ++b) {
                    dp[u].profit_no_discount[b] = get_max(merged_no_discount[b], future[u] - cost + merged_with_discount[b - cost]);
                }
                cost >>= 1;
                for (size_t b = 0; b < cost; ++b) {
                    dp[u].profit_with_discount[b] = merged_no_discount[b];
                }
                for (size_t b = cost; b <= budget; ++b) {
                    dp[u].profit_with_discount[b] = get_max(merged_no_discount[b], future[u] - cost + merged_with_discount[b - cost]);
                }
                break;
            }
        };
    }
    return dp[0].profit_no_discount[budget];
}

#pragma clang attribute pop

uint32_t** convert_graph(size_t n, const vector<vector<int>>& edges) {
    auto adj = pool_allocate<uint32_t*>(n + 1);
    adj[0] = pool_allocate<uint32_t>(edges.size());
    MemoryPoolScope mem_scope;
    auto cnt = pool_allocate<uint32_t>(n);
    fill(cnt, cnt + n, 0);
    for (const auto& e : edges) {
        ++cnt[e[0] - 1];
    }
    for (int i = 0; i < n; ++i) {
        adj[i + 1] = adj[i] + cnt[i];
    }
    for (const auto& e : edges) {
        const auto u = e[0] - 1;
        const auto v = e[1] - 1;
        adj[u][--cnt[u]] = v;
    }
    return adj;
}

class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        __builtin_assume(n >= 1 && n <= 160);
        MemoryPoolScope mem_scope;
        const auto g = convert_graph(n, hierarchy);
        return maxProfitImpl(n, present.data(), future.data(), g, budget);
    }
};
