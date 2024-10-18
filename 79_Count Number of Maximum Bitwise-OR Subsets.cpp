class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int m = 0, c = 0;

        for (int x : nums) {
            m |= x;
        }

        int t = 1 << n;
        for (int mask = 1; mask < t; ++mask) {
            int o = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    o |= nums[i];
                }
            }
            if (o == m) {
                ++c;
            }
        }
        return c;
    }
};
