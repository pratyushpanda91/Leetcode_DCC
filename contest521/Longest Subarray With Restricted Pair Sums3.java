class Solution {
    public int maxSubarray(int[] nums) {
        int[] freq = new int[501];

        int left = 0;
        int ans = 0;

        for(int right = 0; right< nums.length; right++){
            int x = nums[right];
            while(createsInvalid(x, freq)){
                freq[nums[left]]--;
                left++;
            }
            freq[x]++;
            ans = Math.max(ans, right-left+1);
        }
        return ans;
    }
    private boolean createsInvalid(int x, int[] freq){
        for(int a =1;a<x;a++){
            int b = x-a;
            if(freq[a] == 0 || freq[b] == 0)
            continue;

            if(a != b){
                return true;
            }
            if(freq[a] >= 2){
                return true;
            }
        }
        for(int a = 1; x+a <= 500; a++){
            if(freq[a] > 0 && freq[x+a] >0){
                return true;
            }
        }
        return false;
    }
}