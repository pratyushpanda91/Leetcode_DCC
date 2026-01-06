class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        vector<long long> levelSum;
        queue<TreeNode*> q;
        long long sum = 0;
        q.push(root);

        while(!q.empty()) {
            int size =  q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            levelSum.push_back(sum);
            sum = 0;
        }

        return max_element(levelSum.begin(), levelSum.end()) - levelSum.begin() + 1;
    }
};
