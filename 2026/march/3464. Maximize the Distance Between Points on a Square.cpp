uint32_t dists[15000];
uint16_t nxt[15000];

class Solution {
public:
    int maxDistance(int s, vector<vector<int>>& points, int k) {
        const uint64_t n = points.size(), perim = 4UL * s;

        for (uint i = 0; i < n; i++) {
            uint64_t x = points[i][0], y = points[i][1];
            dists[i] = (x == 0 || y == s) ? perim - x - y : x + y;
        }

        sort(dists, dists + n);

        const auto check = [&](uint64_t x) -> bool {
            for (uint i = 0, r = 0; i < n; i++) {
                r = max(r, i + 1);
                while (r < n && dists[r] < dists[i] + x) r++;
                nxt[i] = r;
            }
            uint64_t maxreach = dists[n - 1] + perim - (k - 1) * x;
            auto limit = perim - x;

            for (uint i = 0; i < n && dists[i] <= maxreach; i++) {
                uint j = i;
                for (uint r = k - 1; r > 0 && j != n; r--) {
                    j = nxt[j];
                }
                if (j != n && dists[j] - dists[i] <= limit) return true;
            }
            return false;
        };

        uint64_t lo = 1, hi = perim / k;
        while (lo < hi) {
            auto x = (lo + hi + 1) / 2;
            if (check(x))
                lo = x;
            else
                hi = x - 1;
        }
        return hi;
    }
};
