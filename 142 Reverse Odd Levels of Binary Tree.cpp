class Solution {
public:
    void dfs(TreeNode* left, TreeNode* right, int level) {
        // Base case: if either node is null, return
        if (!left || !right) return;

        // If the current level is odd, swap values of the left and right nodes
        if (level % 2 == 1) {
            swap(left->val, right->val);
        }

        // Recur for the next level
        dfs(left->left, right->right, level + 1); // Left subtree's left child with right subtree's right child
        dfs(left->right, right->left, level + 1); // Left subtree's right child with right subtree's left child
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr;

        // Start the DFS from the first level (level 1 is the children of the root)
        dfs(root->left, root->right, 1);
        return root;
    }
};
