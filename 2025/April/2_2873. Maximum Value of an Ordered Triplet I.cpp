class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long maxi = 0;
            for (int i = 0 ; i < nums.size() ; i++) {
                for (int k = nums.size() - 1 ; k > i ; k--) {
                    int j = i + 1;
                    while (j < k) {
                    maxi = max(maxi,(long(nums[i] - nums[j]) * nums[k]));
                    j++;
                    }
                }
            }
            return maxi < 0 ? 0 : maxi;
        }
    };
