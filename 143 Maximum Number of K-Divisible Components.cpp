class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> tree(n);
        vector<bool> visited(n, false);
        
        // Build the adjacency list for the tree
        for (const auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        
        int components = 0;

        // Helper DFS function
        function<long long(int)> dfs = [&](int node) -> long long {
            visited[node] = true;
            long long subtreeSum = values[node];  // Use long long for large sums
            
            for (int neighbor : tree[node]) {
                if (!visited[neighbor]) {
                    long long childSum = dfs(neighbor);
                    
                    // If the childSum is divisible by k, we can split here
                    if (childSum % k == 0) {
                        components++;
                    } else {
                        // Add the childSum to the current subtreeSum
                        subtreeSum += childSum;
                    }
                }
            }
            return subtreeSum;
        };

        // Start DFS from the root (node 0)
        dfs(0);

        // Add 1 for the root component
        return components + 1;
    }
};
