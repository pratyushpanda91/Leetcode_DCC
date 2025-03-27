class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            unordered_map <int,int> mpp , left;
            for (int i : nums) mpp[i]++;
            for (int i = 0 ; i < nums.size()-1; i++) {
                left[nums[i]]++, mpp[nums[i]]--;
                if (left[nums[i]] * 2 > (i + 1) && mpp[nums[i]] * 2 > (nums.size()-i-1))
                return i;
            }
            return -1;
        }
    };
