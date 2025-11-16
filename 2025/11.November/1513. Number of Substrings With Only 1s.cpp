class Solution {
public:
    const long long mod=1e9+7;
    int numSub(string& s) {
        int count=0;
        long long ans=0;
        for(char c: s){
            if (c=='0'){
                ans=(ans+(long long)count*(count+1)/2%mod);
                count=0;
            }
            else count++;
        }
        ans=(ans+(long long)count*(count+1)/2%mod);// last one
        return ans;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
