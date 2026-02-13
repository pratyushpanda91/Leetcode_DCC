#include <memory_resource>
pmr::unsynchronized_pool_resource pool;
class Solution {
public:
    static int has1(string& s, int n){
        int cnt=1, len=1;
        for(int i=1; i<n; i++){
            if (s[i]==s[i-1]) len++;
            else {
                cnt=max(cnt, len);
                len=1;
            }
        }
        return max(cnt, len);
    }

    static constexpr long long bias=1<<18, shift=32;
    inline static long long pack(int x, int y){
        // Deal with negative int
        return ((long long)(x+bias)<<shift)|(long long)(y+bias);
    }

    static int longestBalanced(string& s) {
        const int n=s.size();
        int ans=has1(s, n);

        pmr::unordered_map<long long, int> ab(&pool), bc(&pool), ca(&pool), abc(&pool);
        
        ab.reserve(n), bc.reserve(n), ca.reserve(n), abc.reserve(n);
        // INITIAL STATE at -1
        abc[pack(0, 0)]=-1;
        ab[pack(0, 0)]=-1; // (A-B, C)
        bc[pack(0, 0)]=-1; // (B-C, A)
        ca[pack(0, 0)]=-1; // (C-A, B)
    
        array<int, 3> cnt={0};
        for(int i=0; i<n; i++){
            cnt[s[i]-'a']++; 
            const auto [A, B, C]=cnt;

            // 3-letter balance: A=B=C
            long long key=pack(B-A, C-A);
            if(abc.count(key)) ans=max(ans, i-abc[key]);
            else abc[key]=i;

            // 2-letter balance: A=B and NO C
            key=pack(A-B, C);
            if(ab.count(key)) ans = max(ans, i-ab[key]);
            else ab[key]=i;

            // 2-letter balance: B=C and NO A
            key=pack(B-C, A);
            if(bc.count(key)) ans=max(ans, i-bc[key]);
            else bc[key]=i;

            // 2-letter balance: C=A and NO B
            key=pack(C-A, B);
            if(ca.count(key)) ans=max(ans, i-ca[key]);
            else ca[key]=i;
        }
        
        return ans;
    }
};