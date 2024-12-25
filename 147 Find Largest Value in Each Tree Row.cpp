class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            int maxVal = INT_MIN; // Initialize to smallest integer value for comparison.

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                maxVal = max(maxVal, node->val); // Update max for the current level.

                if (node->left) q.push(node->left);  // Add left child to the queue.
                if (node->right) q.push(node->right); // Add right child to the queue.
            }

            result.push_back(maxVal); // Add the maximum value for this level to the result.
        }

        return result;
    }
};
