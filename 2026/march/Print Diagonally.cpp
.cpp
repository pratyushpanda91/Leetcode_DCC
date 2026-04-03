class Solution {
public:
    long long countWays(int n, int k) {
        const long long mod = 1e9 + 7;
        
        if (n == 1) return k;
        
        long long same = k;
        long long diff = 1LL * k * (k - 1) % mod;
        
        for (int i = 3; i <= n; i++) {
            long long total = (same + diff) % mod;
            same = diff;
            diff = total * (k - 1) % mod;
        }
        
        return (same + diff) % mod;
    }
};