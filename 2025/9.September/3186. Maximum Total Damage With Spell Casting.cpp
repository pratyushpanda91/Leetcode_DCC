class Solution {
public:
    using info=pair<int, long long>;
    static long long maximumTotalDamage(vector<int>& power) {
        const int n=power.size();
        sort(power.begin(), power.end());

        vector<info> spell={{power[0], power[0]}};
        for(int i=1; i<n; i++){
            int x=power[i]; 
            if (x!=power[i-1]) spell.emplace_back(x, (long long)x);
            else spell.back().second+=x;
        }
        int sz=spell.size();
        vector<long long> dp(sz+1, 0);

        for(int i=sz-1; i>=0; i--){
            long long notake=dp[i+1];
            long long take=0;
            int j=i+1,  x=spell[i].first;
            for(; j<sz && spell[j].first<=x+2; j++);

            take=spell[i].second+dp[j];
            dp[i]=max(take, notake);
        }
        
        return dp[0];
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
