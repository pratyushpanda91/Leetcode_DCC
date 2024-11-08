class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int mask = (1LL << maximumBit) - 1, n = nums.size();
        vector<int> res(n);
        for(int i = 0, curr = 0; i < n; i++) {
            curr ^= nums[i];
            res[n-i-1] = ~curr & mask;
        }
        return res;
    }
};
