class Solution{
public:
    
    struct Info{
        bool isBST;
        int size;
        int minVal;
        int maxVal;
    };
    
    Info solve(Node* root, int &ans){
        if(!root){
            return {true, 0, INT_MAX, INT_MIN};
        }
        
        Info left = solve(root->left, ans);
        Info right = solve(root->right, ans);
        
        Info curr;
        curr.size = left.size + right.size + 1;
        curr.minVal = min(root->data, left.minVal);
        curr.maxVal = max(root->data, right.maxVal);
        
        if(left.isBST && right.isBST &&
           root->data > left.maxVal &&
           root->data < right.minVal){
            
            curr.isBST = true;
            ans = max(ans, curr.size);
        }
        else{
            curr.isBST = false;
        }
        
        return curr;
    }
    
    int largestBst(Node *root)
    {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};
