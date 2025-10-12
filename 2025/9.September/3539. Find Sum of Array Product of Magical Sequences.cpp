static constexpr int MOD=1e9+7;
static int C[31][31]={{0}}; 
class Solution {
    int m, k, n;
    void Pascal(){ 
        if (C[0][0]==1) return;
        for(int i=1; i<=30; i++){ 
            C[i][0]=C[i][i]=1; 
            for(int j=1; j<=i/2; j++){ 
                const int Cij=C[i-1][j-1]+C[i-1][j]; 
                C[i][j]=C[i][i-j]=Cij; 
                
            } 
        }
    }

    long long modPow(long long x, unsigned exp, int mod=MOD){ 
        if (exp==0) return 1; 
        const int bM=31-countl_zero(exp);
        bitset<32> B(exp);
        long long y=x;
        for(int b=bM-1; b>=0; b--)
            y=(y*y%mod)*(B[b]?x:1)%mod;
        return y; 
    }
    unordered_map<int, int> dp;
    int dfs(int m, int k, int i, unsigned flag, vector<int>& nums) {
        const int bz=popcount(flag);
        if (m<0 || k<0 || m+bz<k)
            return 0;
        if (m==0)
            return (k==bz)?1:0;
        if (i>=n) return 0;

        uint64_t key=(m<<5)|(k<<10)|(i<<16)|flag;
        auto it=dp.find(key);
        if (it!=dp.end()) return it->second;

        long long ans=0;
        for (int f=0; f<=m; f++) {
            long long perm=C[m][f]*modPow(nums[i],f)%MOD;

            unsigned newFlag=flag+f;
            unsigned nextFlag=newFlag>>1;
            bool bitContribution=newFlag&1;

            ans=(ans+perm*dfs(m-f, k-bitContribution, i+1, nextFlag, nums))%MOD;
        }

        return dp[key]=ans;
    }

public:
    int magicalSum(int m, int k, vector<int>& nums) {
        Pascal();
        this->m=m;
        this->k=k; 
        n=nums.size();

        return dfs(m, k, 0, 0, nums);
    }
};
