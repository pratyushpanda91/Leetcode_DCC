class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        // Use a fixed-size array for frequency since values are in range 1 to 9
        int freq[100] = {0};
        int count = 0;

        for (auto& d : dominoes) {
            // Encode each domino into a unique number where smaller digit comes first
            int key = min(d[0], d[1]) * 10 + max(d[0], d[1]);
            count += freq[key];  // Add number of same dominoes seen so far
            freq[key]++;
        }

        return count;
    }
};
