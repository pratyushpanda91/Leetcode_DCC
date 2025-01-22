typedef pair<int, int> pii;

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();

        vector<vector<int>> res (n, vector<int>(m, -1));

        queue<pii> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j]) {
                    q.push({i, j});
                    res[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            int qSize = q.size();
            while (qSize) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 or nx >= n or ny < 0 or ny >= m or res[nx][ny] != -1) continue;
                    res[nx][ny] = res[x][y] + 1;
                    q.push({nx, ny});
                }

                qSize--;
            }
        }

        return res;
    }
};
