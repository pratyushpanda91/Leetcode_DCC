class Solution {
  public:
    void inOrder(Node* root, vector<int>& temp) {
        if(!root) return;
        inOrder(root->left, temp);
        temp.push_back(root->data);
        inOrder(root->right, temp);
    }
    
    vector<Node*> findPreSuc(Node* root, int key) {
        vector<int> temp;
        inOrder(root, temp);
        
        auto idx01 = lower_bound(temp.begin(), temp.end(), key);
        auto idx02 = upper_bound(temp.begin(), temp.end(), key);
        
        Node* pre = NULL;
        Node* suc = NULL;
       
        if(idx01 != temp.begin()) {
            pre = new Node(*(idx01 - 1));
        }
   
        if(idx02 != temp.end()) {
            suc = new Node(*idx02);
        }
        
        return {pre, suc};
    }
};
