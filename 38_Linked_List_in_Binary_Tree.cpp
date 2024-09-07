class Solution {
private:
    bool check(ListNode*head, TreeNode*root){
        if(!root)return false;
        if(head->val!=root->val){
            return false;
        }
        if(head->next==NULL){
            return true;
        }
        bool left=false;
        bool right=false;
        if(root->left&&head->next&&root->left->val==head->next->val){
            left=check(head->next,root->left);
        }
        if(root->right&&head->next&&root->right->val==head->next->val){
            right=check(head->next,root->right);
        }
        return left|right;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root){
            return false;
        }
        if(root->val==head->val){
            if(check(head,root)){
                return true;
            }
        }
        return isSubPath(head,root->left)|isSubPath(head,root->right);
    }
};
