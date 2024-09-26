struct Node{
    int s, t;
    Node *left, * right;
    Node(int s, int t): s(s), t(t), left(NULL), right(NULL){}
};
class MyCalendar {
    Node* root;
public:
    MyCalendar(): root(NULL) {}
    
    bool dfs(int s, int t, Node* &curr){
        if (!curr) {
            curr=new Node(s, t);
            return 1;
        }
        if (t<=curr->s) return dfs(s, t, curr->left);
        else if (s>=curr->t) return dfs(s, t, curr->right);
        else return 0;
    }
    bool book(int start, int end) {
        return dfs(start, end, root);
    }
};
