class Solution {
public:
    int minOperations(string s, int k) {
        int64_t z = 0 ;
        for (auto & kk: s) if (kk == '0') ++z ;
        int64_t n =  s.length(), o = n - z ;
        int ans = -1 ;
        if (z == 0) return 0 ;
        for (int64_t i = 1 ; i <= n ; ++i) {
            int64_t p = i * (int64_t)k ;
            if ((p - z) & 1) continue ;
            if (i & 1) {
                if (p >= z && p <= (z * i + o * (i - 1)))  return (int)i ;
            } else {
                if (p >= z && p <= (z * (i - 1) + o * i)) return (int)i ;
            }
        }
        return ans ;
    }
};