class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int MOD = 1000000007;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, 0)));

        dp[0][0][grid[0][0] % k] = 1;

        for (int j = 1; j < m; j++) {
            for (int l = 0; l < k; l++) {
                if (dp[0][j - 1][l] != 0) {
                    dp[0][j][(l + grid[0][j]) % k]++;
                    break;
                }
            }
        }

        for (int i = 1; i < n; i++) {
            for (int l = 0; l < k; l++) {
                if (dp[i - 1][0][l] != 0) {
                    dp[i][0][(l + grid[i][0]) % k]++;
                    break;
                }
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                for (int l = 0; l < k; l++) {
                    int modIndex = (l + grid[i][j]) % k;
                    int top = dp[i - 1][j][l];
                    if (top != 0) {
                        dp[i][j][modIndex] = top;
                    }
                    int left = dp[i][j - 1][l];
                    if (left != 0) {
                        dp[i][j][modIndex] = (dp[i][j][modIndex] + left) % MOD;
                    }
                }
            }
        }

        return dp[n - 1][m - 1][0];
    }
};
