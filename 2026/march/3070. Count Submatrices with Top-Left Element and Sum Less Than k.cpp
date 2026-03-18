class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) 
    {
        int n=grid.size(),m=grid[0].size();

        for(int i=1; i<m; i++)
        {
            grid[0][i] += grid[0][i-1];
        }

        for(int i=1; i<n; i++)
        {
            int prefix=grid[i][0];
            grid[i][0] = grid[i-1][0] + prefix;
            for(int j=1; j<m; j++)
            {
                prefix+=grid[i][j];
                grid[i][j] = grid[i-1][j]+prefix;
            }
        }

        int ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] <= k) ans++;
            }
        }
        return ans;
        
    }
};
