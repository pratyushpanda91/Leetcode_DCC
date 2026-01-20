class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            int v = 1;
            bool found = false;
            while (v < x) {
                if ( ( v | (v+1) ) == x ) {
                    ans.push_back(v);
                    found = true;
                    break;
                }
                ++v;
            }
            if (!found) ans.push_back(-1);
        }
        return ans;
    }
};
