const array<int, 2> POS[26] {
    {0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5},
    {1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5},
    {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {2, 5},
    {3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5},
    {4, 0}, {4, 1}
};
int dp[301][26];

class Solution {
public:
    int minimumDistance(const string& word) {
        int n = word.size();
        fill(begin(dp[n]), end(dp[n]), 0);
        for(int i = n - 1; i >= 1; i--) {
            for(int last = 0; last < 26; last++) {
                dp[i][last] = min(
                    abs(POS[word[i - 1] - 'A'][0] - POS[word[i] - 'A'][0]) + abs(POS[word[i - 1] - 'A'][1] - POS[word[i] - 'A'][1]) + dp[i + 1][last],
                    abs(POS[last][0] - POS[word[i] - 'A'][0]) + abs(POS[last][1] - POS[word[i] - 'A'][1]) + dp[i + 1][word[i - 1] - 'A']
                );
            }
        }
        return *min_element(begin(dp[1]), end(dp[1]));
    }
};
