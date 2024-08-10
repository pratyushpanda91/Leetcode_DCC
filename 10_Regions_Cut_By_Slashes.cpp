class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<int> parent(4 * n * n), rank(4 * n * n, 0);
        
        // Initialize the union-find structure
        iota(parent.begin(), parent.end(), 0);

        // Find function with path compression
        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };

        // Union function with union by rank
        auto unite = [&](int x, int y) {
            int rootX = find(x), rootY = find(y);
            if (rootX != rootY) {
                if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
                else if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
                else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
            }
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int base = 4 * (i * n + j);
                char c = grid[i][j];
                
                // Connect the parts inside the current cell
                if (c == '/') {
                    unite(base, base + 3);
                    unite(base + 1, base + 2);
                } else if (c == '\\') {
                    unite(base, base + 1);
                    unite(base + 2, base + 3);
                } else {
                    unite(base, base + 1);
                    unite(base + 1, base + 2);
                    unite(base + 2, base + 3);
                }

                // Connect with the right cell
                if (j + 1 < n) {
                    unite(base + 1, base + 7);
                }
                
                // Connect with the cell below
                if (i + 1 < n) {
                    unite(base + 2, base + 4 * n);
                }
            }
        }

        // Count distinct regions
        int regions = 0;
        for (int i = 0; i < 4 * n * n; ++i) {
            if (find(i) == i) regions++;
        }
        return regions;
    }
};
