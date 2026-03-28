class Solution {
public:
    static string findTheString(vector<vector<int>>& lcp) {
        const int n=lcp.size();
        string s(n, 'a'-1);
        int id=-1;
        for(int i=0; i<n; i++){
            if (s[i]>='a') continue;
            if (++id>=26) return "";
            for(int j=0; j<n; j++)
                if(lcp[i][j]) s[j]='a'+id;
        }
        for(int i=0; i<n; i++){
            if (lcp[i][i]!=n-i) return "";
            for(int j=0; j<i; j++){
                const int x=lcp[i][j];
                if (x!=lcp[j][i]) return "";
                int y=(i<n-1)?lcp[i+1][j+1]:0;
                y=(s[i]==s[j])?y+1:0;
                if (x!=y) return "";
            }
        }
        return s;
    }
};
