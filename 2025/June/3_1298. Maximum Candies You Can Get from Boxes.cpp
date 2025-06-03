class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {

        int n = status.size();
        vector<bool> hasBox(n, false);
        vector<bool> hasKey(n, false);
        vector<bool> used(n, false);
        queue<int> q;

        // Initially collect all boxes we have
        for (int box : initialBoxes) {
            hasBox[box] = true;
        }

        // Keep exploring while we make progress
        bool progress = true;
        int total = 0;

        while (progress) {
            progress = false;

            for (int i = 0; i < n; ++i) {
                // If we have this box, it's openable (status[i] == 1 or we have the key), and we haven't used it yet
                if (hasBox[i] && (status[i] == 1 || hasKey[i]) && !used[i]) {
                    // Open the box
                    used[i] = true;
                    total += candies[i];
                    progress = true;

                    // Collect keys found in this box
                    for (int k : keys[i]) {
                        hasKey[k] = true;
                    }

                    // Collect boxes found inside this box
                    for (int b : containedBoxes[i]) {
                        hasBox[b] = true;
                    }
                }
            }
        }

        return total;
    }
};
