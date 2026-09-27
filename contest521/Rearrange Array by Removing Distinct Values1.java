class Solution {
    public int[] rearrangeArray(int[] nums) {
        Map<Integer, Integer> freq = new HashMap<>();
        for(int num: nums){
            freq.put(num,freq.getOrDefault(num, 0)+1);
        }
        List<Integer> values = new ArrayList<>(freq.keySet());
        Collections.sort(values);

        int[] ans = new int[nums.length];
        int index = 0;

        while(!freq.isEmpty()){
            for(int value : values){
                if(freq.containsKey(value)){
                    ans[index++] = value;
                    int count = freq.get(value);

                    if(count == 1){
                        freq.remove(value);
                    } else {
                        freq.put(value, count - 1);
                    }
                }
            }
        }
        return ans;
    }
}