class Solution {
    struct DSU {
        vector<int> p;

        DSU(int n) {
            p.resize(n, -1);
        }

        int find(int x) {
            return p[x] < 0 ? x : p[x] = find(p[x]);
        }

        bool unite(int a, int b) {
            a = find(a), b = find(b);

            if (a == b) {
                return false;
            }

            p[b] = a;
            return true;
        }
    };

public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        int edgesUsed = 0;
        int minScore = 200000;
        int minSingle = 200000;
        int minDouble = 200000;

        vector<array<int, 3>> optional;
        optional.reserve(edges.size());

        for (auto& e : edges) {
            int u = e[0], v = e[1], s = e[2];
            bool forced = e[3] == 1;

            if (forced) {
                if (!dsu.unite(u, v)) return -1;
                edgesUsed++;
                minScore = min(minScore, s);
            } else {
                optional.push_back({s, u, v});
            }
        }

        sort(optional.begin(), optional.end(), [](auto& a, auto& b) {
            return a[0] > b[0];
        });

        for (auto& e : optional) {
            int s = e[0], u = e[1], v = e[2];

            if (dsu.unite(u, v)) {
                ++edgesUsed;
                if (edgesUsed == n - k - 1) minSingle = s;
                minDouble = s;
            }
        }

        if (edgesUsed != n - 1) return -1;

        int doubleFactor = !k ? 1 : 2;
        return min({minScore, minSingle, doubleFactor * minDouble});
    }
};
