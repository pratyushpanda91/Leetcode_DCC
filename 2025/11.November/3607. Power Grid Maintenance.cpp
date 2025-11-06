class Solution {
public:
    vector<int> processQueries(int nodes, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        int parents[nodes + 1];
        for (int node = 1; node <= nodes; ++node) {
            parents[node] = node;
        }
        for (vector<int>& connection : connections) {
            parents[unionfind(parents, connection[0])] =
                unionfind(parents, connection[1]);
        }
        int size_q = queries.size();
        vector<bool> online(nodes + 1, true);
        for (int index = 0; index < size_q; ++index) {
            if (queries[index][0] == 2) {
                if (online[queries[index][1]]) {
                    online[queries[index][1]] = false;
                } else {
                    queries[index][0] = 3;
                }
            }
        }
        int groups[nodes + 1];
        memset(&groups, 0, sizeof(groups));
        int order = 1;
        int min_online[nodes + 1];
        for (int node = 1; node <= nodes; ++node) {
            int root = unionfind(parents, node);
            if (groups[root] == 0) {
                groups[root] = order, min_online[order] = INT_MAX, ++order;
            }
            int group = groups[root];
            groups[node] = group;
            if (online[node]) {
                min_online[group] = min(min_online[group], node);
            }
        }
        vector<int> result;
        for (int index = size_q - 1; index >= 0; --index) {
            if (queries[index][0] == 2) {
                online[queries[index][1]] = true,
                min_online[groups[queries[index][1]]] = min(
                    min_online[groups[queries[index][1]]], queries[index][1]);
            } else if (queries[index][0] == 1) {
                if (online[queries[index][1]]) {
                    result.push_back(queries[index][1]);
                } else if (min_online[groups[queries[index][1]]] == INT_MAX) {
                    result.push_back(-1);
                } else {
                    result.push_back(min_online[groups[queries[index][1]]]);
                }
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
    int unionfind(int parents[], int node) {
        if (parents[node] == node) {
            return node;
        }
        parents[node] = unionfind(parents, parents[node]);
        return parents[node];
    }
};
