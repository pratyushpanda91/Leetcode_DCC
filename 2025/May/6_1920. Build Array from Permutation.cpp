class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        const int n=nums.size();
        for(int i=0; i<n; i++)
            nums[i]+=(nums[nums[i]]&1023)<<10;
        for(int i=0; i<n; i++)
            nums[i]>>=10;
        return nums;
    }
};
