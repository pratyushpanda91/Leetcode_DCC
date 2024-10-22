class Solution {
public:
    long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;
        priority_queue<long, vector<long>, greater<long>> pq;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            long sum = 0;
            while (size > 0) {
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
                size--;
            }

            pq.push(sum);

            if (pq.size() > k) pq.pop();
        }
        return pq.size() < k ? -1 : pq.top();
    }
};
