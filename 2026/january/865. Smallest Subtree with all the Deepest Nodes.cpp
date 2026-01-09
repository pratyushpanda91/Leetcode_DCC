class Solution {
public:
    int maxDepth=0;
    TreeNode* lca=NULL;
    int dfs(TreeNode* root, int depth){
        maxDepth=max(maxDepth, depth);
        if (!root) return depth;
        int l=dfs(root->left, depth+1);
        int r=dfs(root->right, depth+1);
        if (l==maxDepth && r==maxDepth) lca=root;
        return max(l, r);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root, 0);
        return lca;
    }
};
