class Solution {
public:
    int dp[51];
    int solve(int idx, string& s, unordered_map<string, int>& mp){
        if(idx >= s.length()){
            return 0;
        }
        if(dp[idx] != -1) return dp[idx];
        int ans = INT_MAX;
        string k = "";
        for(int i = idx; i < s.length(); i++){
            k.push_back(s[i]);
            int count = ((mp[k]) ? 0 : k.length()) + solve(i + 1, s, mp);
            ans = min(ans, count);
        }
        return dp[idx] = ans;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string, int> mp;
        for (auto it : dictionary) {
            mp[it]++;
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, s, mp);
    }
};
