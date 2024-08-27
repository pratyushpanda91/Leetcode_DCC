class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> dist(n, 0.0);
        dist[start_node] = 1.0;
        
        for (int i = 0; i < n - 1; i++) {
            bool updated = false;
            for (int j = 0; j < edges.size(); j++) {
                int u = edges[j][0];
                int v = edges[j][1];
                double prob = succProb[j];
             
                if (dist[u] * prob > dist[v]) {
                    dist[v] = dist[u] * prob;
                    updated = true;
                }
                
                if (dist[v] * prob > dist[u]) {
                    dist[u] = dist[v] * prob;
                    updated = true;
                }
            }
            if (!updated) break;
        }
        return dist[end_node];
    }
};
