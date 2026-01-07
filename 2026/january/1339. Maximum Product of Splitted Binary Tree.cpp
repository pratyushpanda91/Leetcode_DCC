class Solution {
public:
    const int mod=1e9+7;
    long long ans=INT_MIN, total=0;
    int dfs(TreeNode* root, bool compute_ans=0){
        if (!root) return 0;
        int sum=root->val
            +dfs(root->left, compute_ans)
            +dfs(root->right, compute_ans);
        if (compute_ans) ans=max(ans, (total-sum)*sum);
        return sum;
    }
    int maxProduct(TreeNode* root) {
        total=dfs(root);
        dfs(root, 1);
        return ans%mod;
    }
};



auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
