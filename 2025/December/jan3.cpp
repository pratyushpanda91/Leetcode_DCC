class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1000000007;
        long long x = 6, y = 6;

        for (int i = 2; i <= n; i++) {
            long long new_x = (3 * x + 2 * y) % MOD;
            long long new_y = (2 * x + 2 * y) % MOD;
            x = new_x;
            y = new_y;
        }

        return (x + y) % MOD;
    }
};