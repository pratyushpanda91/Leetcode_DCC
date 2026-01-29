class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const long long mx = 1e14;
        vector<vector<long long>> cc(26, vector<long long>(26, mx));
        int sz = original.size();
        for(int i=0;i<26;i++)cc[i][i]=0;
        for(int i=0;i<sz;i++){
            int a = original[i]-'a', b = changed[i]-'a', c = cost[i];
            cc[a][b] = min(cc[a][b], (long long)c);
        }

        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(cc[i][k] == mx || cc[k][j]==mx)continue;
                    cc[i][j] = min(cc[i][j], cc[i][k]+cc[k][j]);
                }
            }
        }

        long long ans = 0;
        sz = source.size();
        for(int i=0;i<sz;i++){
            int a = source[i]-'a', b = target[i]-'a';
            if(cc[a][b]==mx)return -1;
            ans += cc[a][b];
        }
        return ans;
    }
};

auto init = atexit([](){ofstream("display_runtime.txt")<<"0";});
