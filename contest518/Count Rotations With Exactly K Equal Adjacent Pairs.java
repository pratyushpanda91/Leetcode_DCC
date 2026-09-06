class Solution {
    public int countRotations(String s, int k) {
     int n = s.length();

        //count adj pairs in cir strings
        int equalPairs = 0;
        for(int i = 0;i<n;i++){
            if(s.charAt(i) == s.charAt((i+1) % n)){
                equalPairs++;
            }
        }
        if(k == equalPairs -1){
            return equalPairs;
        }
        if(k == equalPairs){
            return n - equalPairs;
        }
        return 0;
    }
}
