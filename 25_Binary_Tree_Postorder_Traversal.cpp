class Solution {
public:
    vector<int> num={};
    vector<int> postorderTraversal(TreeNode* root) {
        if (root==nullptr)
            return num;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        num.push_back(root->val);
        return num;
    }
};
