class Solution {
public:
    string smallestNumber(string& pattern) {
        const int n=pattern.size();
        vector<char> succD(n, 0);
        succD.back()+=(pattern.back()=='D');
        for(int i=n-2; i>=0; i--)
            succD[i]=(pattern[i]=='D')?succD[i+1]+1:0;
        string ans(n+1, ' ');
        iota(ans.begin(), ans.end(), '1');
        int i=0;
        while(i<n){
            if (pattern[i]=='D'){
                int l=i, r=i+succD[i];
                while(l<r){
                    swap(ans[l++], ans[r--]);
                }
            }
            i+=succD[i]+1;
        }
        return ans;
    }
};
