class Solution {
public:
    int dfs(vector<vector<int>>&adj, int node, int t, map<int,int>&visited, vector<int>&amount) {
        int currVal = amount[node];
        if (visited.count(node)) {
            if (visited[node] < t) currVal = 0;
            else if (visited[node] == t) currVal /= 2;
        }
        if (adj[node].size() == 0) return currVal;
        int res = INT_MIN;
        for (auto nbr : adj[node]) {
            res = max(res, dfs(adj, nbr, t+1, visited, amount));
        }
        return currVal + res;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n, vector<int>());
        vector<vector<int>> tree(n, vector<int>());
        vector<int> parent(n, 0);

        for (int i = 0; i < n-1; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> added(n, 0);
        queue<int> q;
        q.push(0);
        added[0] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto nbr : adj[node]) {
                if (!added[nbr]) {
                    added[nbr]++;
                    tree[node].push_back(nbr);
                    q.push(nbr);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (auto child : tree[i]) {
                parent[child] = i;
            }
        }

        map<int, int> visited;
        int t = 0;
        int node = bob;
        while (node != 0) {
            visited[node] = t++;
            node = parent[node];
        }
        return dfs(tree, 0, 0, visited, amount);
    }
};
