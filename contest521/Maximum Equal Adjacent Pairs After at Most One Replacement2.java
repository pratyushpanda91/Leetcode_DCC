class Solution {
    public int maxEqualAdjacentPairs(int[] nums) {
        int n = nums.length;
        int base = 0;
        Map<String, Integer> map = new HashMap<>();
        for(int i = 0; i<n-1; i++){
            if(nums[i] == nums[i+1]){
                base++;
            } else {
                int a = Math.min(nums[i], nums[i+1]);
                int b = Math.max(nums[i], nums[i+1]);
                String key = a + "#" + b;
                map.put(key, map.getOrDefault(key, 0) + 1);
            }
        }
        int max = 0;
        for(int count : map.values()){
            max = Math.max(max,count);
        }
        return base+max;
    }
}