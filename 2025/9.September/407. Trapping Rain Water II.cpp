class Solution {
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        
        const int m = heightMap.size();
        const int n = heightMap[0].size();
        
        priority_queue<pair<int, pair<int, int>>, 
                      vector<pair<int, pair<int, int>>>, 
                      greater<>> pq;
                      
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int j = 0; j < n; j++) {
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[m-1][j], {m-1, j}});
            visited[0][j] = visited[m-1][j] = true;
        }
        
        for (int i = 1; i < m-1; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n-1], {i, n-1}});
            visited[i][0] = visited[i][n-1] = true;
        }
        
        int water = 0;
        while (!pq.empty()) {
            auto [height, coords] = pq.top();
            auto [row, col] = coords;
            pq.pop();
            
            for (int k = 0; k < 4; k++) {
                int newRow = row + dx[k];
                int newCol = col + dy[k];
                
                if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || 
                    visited[newRow][newCol]) continue;
                
                if (heightMap[newRow][newCol] < height) {
                    water += height - heightMap[newRow][newCol];
                    pq.push({height, {newRow, newCol}});
                } else {
                    pq.push({heightMap[newRow][newCol], {newRow, newCol}});
                }
                visited[newRow][newCol] = true;
            }
        }
        return water;
    }
};
