class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int maxlen=1;
        int l=0;
        for(int r=0;r<nums.size();r++)
        {
            while((long long)nums[r]>(long long)nums[l]*k)
            {
                l++;
            }
            maxlen=max(maxlen,r-l+1);
        }
        return nums.size()-maxlen;

    }
};
