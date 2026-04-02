class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        vector<vector<int>> dfs(vector<vector<int>>(coins[0].size()+1,vector<int>(3,INT_MIN/2)));



        for(int i =0 ;i < coins.size();i++){
            for(int j = 0;j < coins[0].size();j++){
                if(i == 0 && j == 0){
                    dfs[1][0] = coins[i][j];
                    dfs[1][1] = max(coins[i][j],0);
                    dfs[1][2] = max(coins[i][j],0);
                }
                else{
  
                    dfs[j+1][2] = max(coins[i][j] + max(dfs[j+1][2],dfs[j][2]),max(dfs[j+1][1],dfs[j][1]));
                    dfs[j+1][1] = max(coins[i][j] + max(dfs[j+1][1],dfs[j][1]),max(dfs[j+1][0],dfs[j][0]));
                    dfs[j+1][0] = coins[i][j]+max(dfs[j+1][0],dfs[j][0]);
                    
                }
            }
        }
        return max({dfs[coins[0].size()][0],dfs[coins[0].size()][1],dfs[coins[0].size()][2]});


    }
};
