class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;

        // Create a DP array up to `high`
        vector<int> dp(high + 1, 0);
        dp[0] = 1; // Base case: one way to construct an empty string

        // Fill DP array
        for (int i = 0; i <= high; ++i) {
            if (dp[i] > 0) {
                // Add `zero` characters
                if (i + zero <= high) {
                    dp[i + zero] = (dp[i + zero] + dp[i]) % MOD;
                }
                // Add `one` characters
                if (i + one <= high) {
                    dp[i + one] = (dp[i + one] + dp[i]) % MOD;
                }
            }
        }

        // Count good strings in range [low, high]
        int result = 0;
        for (int i = low; i <= high; ++i) {
            result = (result + dp[i]) % MOD;
        }

        return result;
    }
};
