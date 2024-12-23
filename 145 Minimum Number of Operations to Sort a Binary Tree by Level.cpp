class Solution {
public:
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;

        // BFS to process each level of the tree
        queue<TreeNode*> q;
        q.push(root);

        int totalSwaps = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<int> levelValues;

            // Collect all values at the current level
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelValues.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Add the minimum swaps needed to sort this level
            totalSwaps += minSwapsToSort(levelValues);
        }

        return totalSwaps;
    }

private:
    int minSwapsToSort(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> numWithIndex(n);

        // Pair each number with its index
        for (int i = 0; i < n; ++i) {
            numWithIndex[i] = {nums[i], i};
        }

        // Sort the array by value
        sort(numWithIndex.begin(), numWithIndex.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        // Count cycles in the permutation
        for (int i = 0; i < n; ++i) {
            if (visited[i] || numWithIndex[i].second == i) continue;

            int cycleSize = 0;
            int j = i;

            // Traverse the cycle
            while (!visited[j]) {
                visited[j] = true;
                j = numWithIndex[j].second;
                ++cycleSize;
            }

            // Add swaps for this cycle
            if (cycleSize > 1) {
                swaps += cycleSize - 1;
            }
        }

        return swaps;
    }
};
