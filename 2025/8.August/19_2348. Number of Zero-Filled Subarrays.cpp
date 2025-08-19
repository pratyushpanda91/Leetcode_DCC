class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                res += (count * (count + 1)) / 2;
                count = 0;
            } else 
                ++count;
        }
        res += (count * (count + 1)) / 2;
        return res;
    }
};
