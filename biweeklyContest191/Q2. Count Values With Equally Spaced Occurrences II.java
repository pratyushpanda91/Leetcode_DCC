class Solution {
    public int countSpecialIntegers(int[] nums) {
        HashMap<Integer, int[]> map = new HashMap<>();
        for(int i = 0; i < nums.length; i++){
            int x = nums[i];
            if(!map.containsKey(x)){
                map.put(x, new int[]{1, i, -1, 1});
            } else {
                int[] data = map.get(x);
                int count = data[0];
                int previousIndex = data[1];
                int gap = data[2];
                int currentGap = i - previousIndex;
                count++;
                if(count == 2){
                    gap = currentGap;
                } else if(currentGap != gap){
                    data[3] = 0;
                }
                data[0]=count;
                data[1]=i;
                data[2]=gap;
            }
        }
        int ans = 0;
        for(int[] data : map.values()){
            int count = data[0];
            int valid = data[3];
            if(count >= 3 && valid == 1){
                ans++;
            }
        }
        return ans;
    }
}©leetcode
