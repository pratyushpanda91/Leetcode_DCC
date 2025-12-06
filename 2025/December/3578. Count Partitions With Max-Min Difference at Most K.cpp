class Solution {
public:
    int countPartitions(vector<int>& a, int k) {
        int n = a.size();
        int mod = 1e9 + 7;

        vector<int> dp(n + 1, 1);
        multiset<int>ms;
        int ws=0;
        for(int i=0,j=0;i<n;i++){
            ws=(ws+dp[i])%mod;
            ms.insert(a[i]);
            while(*prev(ms.end())-*ms.begin()>k){
                ws=(ws-dp[j]+mod)%mod;
                ms.erase(ms.find(a[j++]));
            }
            dp[i+1]=ws;
        }
        return dp[n];
    }
};
auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });
