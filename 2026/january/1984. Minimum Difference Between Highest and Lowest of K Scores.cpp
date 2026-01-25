class Solution {
public:
    static int minimumDifference(vector<int>& nums, int k) {
        const int n=nums.size();
        if (k==1) return 0; 
        sort(nums.begin(), nums.end());
        int diff=INT_MAX;
        for(int l=0, r=k-1; r<n; r++, l++){
            diff=min(diff, nums[r]-nums[l]);
        }
        return diff;
    }
};
