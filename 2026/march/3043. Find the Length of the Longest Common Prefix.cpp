struct TrieNode {
    TrieNode* next[10]; 
    bool isEnd=0;
};
static constexpr int N=9e5;  
static TrieNode pool[N];
static int ptr=0;  
struct Trie {
    TrieNode* newNode() {
        TrieNode* node=&pool[ptr++];
        memset(node->next, 0, sizeof(node->next));
        node->isEnd=0;
        return node;
    }
public:
    TrieNode* root;
    Trie(){
        ptr=0; 
        root=newNode();
    }
    void insert(string&& word) {
        TrieNode* Node=root;
        for(char c: word){
            int i=c-'0';
            if(Node->next[i]==NULL)
                Node->next[i]=newNode();
            Node=Node->next[i];
        }
        Node->isEnd=1;
    }
    
    int commonPrefix(string&& s) {
        TrieNode* Node =root;
        int len=0;
        for(char c : s){
            int i = c - '0';
            if(Node->next[i]==NULL) return len;
            Node = Node->next[i];
            len++;
        }
        return len;
        
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie=Trie();
        for (int x: arr2)
            trie.insert(to_string(x));
        int maxLen=0;
        for (int x: arr1)
            maxLen=max(maxLen, trie.commonPrefix(to_string(x)));
        return maxLen;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();