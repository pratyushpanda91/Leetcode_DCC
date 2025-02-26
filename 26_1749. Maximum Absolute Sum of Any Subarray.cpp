class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum=0, minSum=0;
        for(int x: nums){
            maxSum=max(0, maxSum+x);
            minSum=min(0, minSum+x);
        }
        return maxSum-minSum;
    }
};
