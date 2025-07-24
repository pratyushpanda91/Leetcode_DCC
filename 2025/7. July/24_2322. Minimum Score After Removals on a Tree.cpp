class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> graph(n);
        vector<unordered_set<int>> children(n);
        vector<int> xor_val(nums);
        vector<int> degree(n, 0);

        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        int total = 0;
        queue<int> q;
        vector<bool> seen(n, false);

        for (int i = 0; i < n; ++i) {
            total ^= nums[i];
            if (degree[i] == 1) {
                q.push(i);
                seen[i] = true;
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int next : graph[cur]) {
                if (!seen[next]) {
                    children[next].insert(cur);
                    children[next].insert(children[cur].begin(), children[cur].end());
                    xor_val[next] ^= xor_val[cur];
                }
                degree[next]--;
                if (degree[next] == 1 && !seen[next]) {
                    seen[next] = true;
                    q.push(next);
                }
            }
        }

        int res = INT_MAX;
        int m = edges.size();
        for (int i = 0; i < m - 1; ++i) {
            for (int j = i + 1; j < m; ++j) {
                int a = edges[i][0], b = edges[i][1];
                if (children[a].count(b)) swap(a, b);

                int c = edges[j][0], d = edges[j][1];
                if (children[c].count(d)) swap(c, d);

                vector<int> vals;
                if (children[a].count(c)) {
                    vals = {xor_val[c], xor_val[a] ^ xor_val[c], total ^ xor_val[a]};
                } else if (children[c].count(a)) {
                    vals = {xor_val[a], xor_val[c] ^ xor_val[a], total ^ xor_val[c]};
                } else {
                    vals = {xor_val[a], xor_val[c], total ^ xor_val[a] ^ xor_val[c]};
                }

                int max_v = *max_element(vals.begin(), vals.end());
                int min_v = *min_element(vals.begin(), vals.end());
                res = min(res, max_v - min_v);
            }
        }

        return res;
    }
};
