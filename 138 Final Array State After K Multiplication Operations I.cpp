class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
         int n = nums.size();
        
        // Perform k operations
        for (int i = 0; i < k; ++i) {
            // Find the index of the first minimum value
            int minIndex = 0;
            for (int j = 1; j < n; ++j) {
                if (nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
            }
            // Multiply the minimum value by the multiplier
            nums[minIndex] *= multiplier;
        }
        
        return nums;
    }
};
