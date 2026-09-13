class Solution {
    public long minOperations(int[] nums) {
        long ans = 0;
        for(int x: nums){
            ans += getMinOperations(x);
        }
        return ans;
    }
    private long getMinOperations(int x){
        String s = String.valueOf(x);
        int n = s.length();

        int half = (n+1) / 2;
        long prefix = Long.parseLong(s.substring(0, half));
        long base = power10(half - 1);
        long best = Long.MAX_VALUE;

        long[] prefixes = {
            prefix - 10,
            prefix -1,
            prefix,
            prefix+1, 
            prefix + 10
        };

        for(long p: prefixes){
            if(p<base){
                continue;
            }
            long palindrome = makePalindrome(p, n);
            if(palindrome > 0 && palindrome % 2 == x % 2){
                best = Math.min(best, Math.abs((long) x-palindrome)/2);
            }
        }
        if(n>1){
            int len = n-1;
            int h = (len + 1)/2;
            long b = power10(h-1);
            long p;
            if(x % 2 ==1){
                p = 10*b-1;
            } else {
                p = 8 * b + (b - 1);
                
            }
            long palindrome = makePalindrome(p, len);

            if(palindrome > 0 && palindrome % 2 == x % 2){
                best = Math.min(best, Math.abs((long)x - palindrome)/ 2);
            }
        }
        {
            int len = n+1;
            int h = (len+1)/2;
            long b = power10(h-1);
            long p;

            if(x % 2 == 1){
                p = b;
            } else {
                p = 2 * b;
            }
            long palindrome = makePalindrome(p,len);
            if(palindrome > 0 && palindrome % 2 == x%2){
                best =Math.min(best, Math.abs((long)x - palindrome)/2);
            }
        }
        return best;
        
    }
    private long makePalindrome(long prefix, int length){
        String s = String.valueOf(prefix);
        StringBuilder sb = new StringBuilder(s);

        if(length % 2 == 1){
            sb.append(new StringBuilder(s.substring(0, s.length() - 1)).reverse());
        } else {
            sb.append(new StringBuilder(s).reverse());
        }

        return Long.parseLong(sb.toString());
    }
    private long power10(int n){
        long result = 1;
        for(int i = 0; i<n; i++){
            result *= 10;
        }
        return result;
    }
}