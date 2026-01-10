class Solution {
public:
    int dp[1001][1001];

    int solve(string& s1, string& s2, int i, int j) {
        if (i >= s1.size() && j >= s2.size()) {
            return 0;
        }

        if (i >= s1.size()) {
            int sum = 0;
            for (int k = j; k < s2.size(); k++) {
                sum += (int)s2[k];
            }
            return sum;
        }

        if (j >= s2.size()) {
            int sum = 0;
            for (int k = i; k < s1.size(); k++) {
                sum += (int)s1[k];
            }
            return sum;
        }

        if (dp[i][j] != -1) return dp[i][j];

        int ans;
        if (s1[i] == s2[j]) {
            ans = solve(s1, s2, i + 1, j + 1);
        } else {
            int deleteS1 = (int)s1[i] + solve(s1, s2, i + 1, j);
            int deleteS2 = (int)s2[j] + solve(s1, s2, i, j + 1);
            ans = min(deleteS1, deleteS2);
        }

        return dp[i][j] = ans;
    }

    int minimumDeleteSum(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, 0, 0);
    }
};
