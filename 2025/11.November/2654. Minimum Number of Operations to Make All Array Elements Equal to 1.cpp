class Solution {
public:
    static int minOperations(vector<int>& nums) {
        const int n=nums.size(), cnt1=count(nums.begin(), nums.end(), 1);
        if (cnt1>0) return n-cnt1;
        for(int d=2; d<=n; d++){
            for(int l=0; l<=n-d; l++){
                int g=nums[l]=gcd(nums[l], nums[l+1]);
                if (g==1) return d+n-2;
            }
        }
        return -1;
    }
};
