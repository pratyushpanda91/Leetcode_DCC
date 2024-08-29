class Solution {
public:    
    vector<int> row[10001], col[10001];
    bitset<1001> viz;

    void dfs(int idx, vector<vector<int>>& stones) {
        const int i = stones[idx][0], j=stones[idx][1];
        viz[idx]=1;
        for (auto k : row[i]) {
            if (!viz[k]) dfs(k, stones);
        }
        for (auto k : col[j]) {
            if (!viz[k]) dfs(k, stones);
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        const int n=stones.size();

        for (int idx=0; idx<n; idx++) {
            const int i = stones[idx][0], j = stones[idx][1];
            row[i].push_back(idx);
            col[j].push_back(idx);
        }
        
        int component=0;
        for  (int idx=0; idx<n; idx++) {
            const int i = stones[idx][0], j = stones[idx][1];
            if (!viz[idx]) {
                dfs(idx, stones); 
                component++;
            }
        }
        return n-component;
    }
};
