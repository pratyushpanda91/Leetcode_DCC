class Solution {
    long long bitSum[100005];
    int bitCount[100005];
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size(), targetK = k - 1;
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        int m = sorted.size();
        memset(bitSum, 0, sizeof(bitSum));
        memset(bitCount, 0, sizeof(bitCount));

        auto update = [&](int idx, int val, int cnt) {
            for (; idx <= m; idx += idx & -idx) {
                bitSum[idx] += val;
                bitCount[idx] += cnt;
            }
        };

        long long minExtra = LLONG_MAX;
        int maxP = m > 0 ? 1 << (31 - __builtin_clz(m)) : 0;
        for (int i = 1; i < n; ++i) {
            int r = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin() + 1;
            update(r, nums[i], 1);
            if (i > dist + 1) {
                int oldV = nums[i - dist - 1];
                int oldR = lower_bound(sorted.begin(), sorted.end(), oldV) - sorted.begin() + 1;
                update(oldR, -oldV, -1);
            }
            if (i >= targetK) {
                int idx = 0, cc = 0; long long cs = 0;
                for (int p = maxP; p > 0; p >>= 1) {
                    if (idx + p <= m && cc + bitCount[idx + p] < targetK) {
                        idx += p; cc += bitCount[idx]; cs += bitSum[idx];
                    }
                }
                if (cc < targetK) cs += (long long)(targetK - cc) * sorted[idx];
                minExtra = min(minExtra, cs);
            }
        }
        return nums[0] + minExtra;
    }
};
