int dp[7][2][10];
unsigned mask=(1<<2)|(1<<5)|(1<<6)|(1<<9);
unsigned invalid=(1<<3)|(1<<4)|(1<<7);
class Solution {
public:
    static int  f(int i, bool tight, int prev, string& s){
        if (i==6) return prev>0;
        if (dp[i][tight][prev]!=-1) return dp[i][tight][prev];
        int cnt=0;

        int lim=tight?(s[i]-'0'):9;

        for(int d=0; d<=lim; d++){
            bool nxtTight=tight & (d==lim);
            if ((1<<d)& invalid) continue;
          
            if ((1<<d) & mask) cnt+=f(i+1, nxtTight, d, s);
            else cnt+=f(i+1, nxtTight, prev, s);
        }
        return dp[i][tight][prev]=cnt;
    }
    static inline string toS(int n){
        string s(6, '0');
        for(int x=n, i=5; x; x/=10, i--){
            s[i]='0'+x%10;
        }
        return s;
    }
    static int rotatedDigits(int n) {
        string s=toS(n);
        memset(dp, -1, sizeof(dp));
        return f(0, 1, 0, s);
    }
};