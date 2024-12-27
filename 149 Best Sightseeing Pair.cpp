#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max_i = values[0]; // Initialize max_i as values[0] + 0 (implicitly)
        int max_score = 0;     // Maximum score found so far

        for (int j = 1; j < values.size(); ++j) {
            // Calculate score for the current pair (max_i + values[j] - j)
            max_score = max(max_score, max_i + values[j] - j);

            // Update max_i to include the current values[j] + j
            max_i = max(max_i, values[j] + j);
        }

        return max_score;
    }
};
