class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        const int m=grid.size(), n=grid[0].size();
        int row[250]={0}, col[250]={0}, cnt=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if (grid[i][j]){
                    cnt++;
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if (grid[i][j]&& row[i]==1 && col[j]==1){
                    cnt--;
                }
            }
        }
        return cnt;
    }
};
