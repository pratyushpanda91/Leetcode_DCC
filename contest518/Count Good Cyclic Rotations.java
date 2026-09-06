class Solution {
    public int countGoodRotations(int[] nums) {
        int n = nums.length;
        int half = n /2;
        long total = 0;
        for(int num:nums){
            total += num;
        }
        long windowSum = 0;
        for(int i = 0; i<half;i++){
            windowSum += nums[i];
        }
        int ans = 0;
        for(int i = 0; i<n;i++){
            if(2 * windowSum > total){
                ans++;
            }
            windowSum -= nums[i];
            windowSum += nums[(i + half) % n];
        }
        return ans;
    }
}
