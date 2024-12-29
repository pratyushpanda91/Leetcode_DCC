class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int MOD = 1e9 + 7;
        int m = words[0].size(); // Number of columns
        int n = target.size();   // Length of the target

        // Precompute character frequencies for each column
        vector<vector<int>> freq(m, vector<int>(26, 0));
        for (const string& word : words) {
            for (int i = 0; i < m; ++i) {
                freq[i][word[i] - 'a']++;
            }
        }

        // DP table: dp[col][pos]
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        dp[0][0] = 1; // Base case: 1 way to form an empty target

        // Fill the DP table
        for (int col = 1; col <= m; ++col) {
            for (int pos = 0; pos <= n; ++pos) {
                // Skip the current column
                dp[col][pos] = dp[col - 1][pos];

                // Use the current column (if pos > 0)
                if (pos > 0) {
                    char targetChar = target[pos - 1];
                    dp[col][pos] += dp[col - 1][pos - 1] * freq[col - 1][targetChar - 'a'];
                    dp[col][pos] %= MOD;
                }
            }
        }

        return dp[m][n];
    }
};
