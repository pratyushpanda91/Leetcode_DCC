class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n);
        dp[n-1]=questions[n-1][0];
        for(int i=n-2; i>=0; i--){
            dp[i]=questions[i][0];
            int skip=questions[i][1];
            if (i+skip < n-1) 
                dp[i]+=dp[i+skip+1];
            dp[i]=max(dp[i], dp[i+1]);
        }
        return dp[0];       
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
