class Solution {
    public long shadowPairs(int[] nums) {
        int n = nums.length;
        int[] R = new int[n];
        int[] stack = new int[n];
        int sp = -1;

        for(int i = 0; i<n; i++){
            while(sp>=0 && nums[stack[sp]] > nums[i]){
                R[stack[sp]] = i;
                sp--;
            }
            stack[++sp] = i;
        }
        while(sp>=0){
            R[stack[sp]] = n;
            sp--;
        }
        long firstSum = 0;
        for(int i = 0; i<n;i++){
            firstSum += (long)(R[i] - i-1);
        }
        int[] gVal = new int[n];
        long[] gCnt = new long[n];
        int top = -1;
        long secondSum = 0;

        for(int i = 0; i<n;i++){
            int x = nums[i];
            while(top>= 0 && gVal[top] > x){
                long c = gCnt[top];
                secondSum += c * (c-1) / 2;
                top--;
            }
            if(top>= 0 && gVal[top] > x){
                gCnt[top]++;
            }else {
                top++;
                gVal[top] = x;
                gCnt[top] = 1;
            }
        }
        while(top>=0){
            long c = gCnt[top];
            secondSum += c * (c-1)/2;
            top--;
        }
        return firstSum - secondSum;
    }
}
