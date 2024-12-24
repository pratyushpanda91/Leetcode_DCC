class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // Function to compute tree properties: diameter and height
        auto treeProperties = [](int n, vector<vector<int>>& edges) {
            vector<vector<int>> graph(n);
            for (const auto& edge : edges) {
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
            }

            // BFS to find farthest node and distance
            auto bfs = [&](int start) {
                vector<int> visited(n, -1);
                queue<int> q;
                q.push(start);
                visited[start] = 0;

                int farthestNode = start, maxDistance = 0;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (int neighbor : graph[node]) {
                        if (visited[neighbor] == -1) {
                            visited[neighbor] = visited[node] + 1;
                            q.push(neighbor);
                            if (visited[neighbor] > maxDistance) {
                                maxDistance = visited[neighbor];
                                farthestNode = neighbor;
                            }
                        }
                    }
                }
                return make_pair(farthestNode, maxDistance);
            };

            // First BFS to find farthest node
            auto [farthest, _] = bfs(0);
            // Second BFS to find the diameter
            auto [_, diameter] = bfs(farthest);
            // Height is half of the diameter rounded up
            int height = (diameter + 1) / 2;

            return make_pair(diameter, height);
        };

        // Compute properties for both trees
        int n1 = edges1.size() + 1, n2 = edges2.size() + 1;
        auto [diameter1, height1] = treeProperties(n1, edges1);
        auto [diameter2, height2] = treeProperties(n2, edges2);

        // Calculate the minimum possible diameter after merging
        return max({diameter1, diameter2, height1 + height2 + 1});
    }
};
