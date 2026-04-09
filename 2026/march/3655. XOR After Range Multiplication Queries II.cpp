using u64 = uint64_t;
constexpr u64 MOD = 1'000'000'007;
constexpr u64 MAXN = 100'000;
constexpr u64 BLOCK = 150;
constexpr u64 VBITS = 30, SBITS = 17, RBITS = 8;
constexpr u64 VMASK = (1 << VBITS) - 1, SMASK = (1 << SBITS) - 1, RMASK = (1 << RBITS) - 1;
constexpr u64 SSHIFT = VBITS, RSHIFT = SSHIFT + SBITS, KSHIFT = RSHIFT + RBITS;

static u64 inv[MAXN + 1];
static u64 events[MAXN];

inline u64 pack(u64 k, u64 res, u64 st, u64 v) {
    return k << KSHIFT | res << RSHIFT | st << SSHIFT | v;
}

inline array<u64, 4> unpack(u64 e) {
    return {e >> KSHIFT, (e >> RSHIFT) & RMASK, (e >> SSHIFT) & SMASK, e & VMASK};
}

class Solution {
public:
    static void init() {
        inv[1] = 1;
        for (u64 v = 2; v <= MAXN; v++)
            inv[v] = MOD - (MOD / v) * inv[MOD % v] % MOD;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        u64 ev = 0, n = nums.size();

        for (auto& q : queries) {
            u64 l = q[0], r = q[1], k = q[2], v = q[3];
            if (v == 1) {
                continue;
            } else if ((r - l + 1) < BLOCK || k > BLOCK) {
                for (u64 idx = l; idx <= r; idx += k)
                    nums[idx] = nums[idx] * v % MOD;
            } else {
                u64 res = l % k;
                events[ev++] = pack(k, res, (l - res) / k, v);
                if (u64 st = (r - res) / k + 1; st <= (n - 1 - res) / k)
                    events[ev++] = pack(k, res, st, inv[v]);
            }
        }

        sort(events, events + ev);

        auto [prevk, prevres, _, __] = unpack(events[0]);
        u64 idx = prevres, j = 0, mul = 1;

        auto flush = [&]() {
            if (ev == 0 || mul == 1) return;
            for (; idx < n; idx += prevk)
                nums[idx] = nums[idx] * mul % MOD;
        };

        for (u64 e : span(events, ev)) {
            auto [k, res, st, v] = unpack(e);
            if (k != prevk || res != prevres) {
                flush();
                prevk = k, prevres = res, idx = res, j = 0, mul = 1;
            }
            for (; j < st; idx += k, j++) {
                nums[idx] = nums[idx] * mul % MOD;
            }
            mul = mul * v % MOD;
        }
        flush();
        return reduce(nums.begin(), nums.end(), 0, bit_xor());
    }
};

const auto init = []() noexcept {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution::init();
    return 'c';
}();
