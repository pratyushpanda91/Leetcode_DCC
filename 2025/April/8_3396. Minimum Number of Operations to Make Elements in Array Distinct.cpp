class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> mpp(101);
        for (int i = nums.size() - 1; i >= 0; --i)
            if (++mpp[nums[i]] > 1) 
                return (i + 3) / 3;
        return 0;
    }
};
