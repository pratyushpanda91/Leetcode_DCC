class Solution {
    public int minDays(int n) {
        int INF = 1000000000;
        int[] dp = new int[n+1];
        for(int i = 1; i<= n; i++){
            dp[i] = INF;
        }

        dp[0] = 0;
        for(int k = 1; k * (k+1)/2 <= n; k++){
            int points = k * (k+1)/2;
            int cost = k+1;
            for(int sum = points; sum <= n; sum++){
                dp[sum] = Math.min(
                    dp[sum],
                    dp[sum-points] + cost);
                
            }
        }
        return dp[n] - 1;
        
    }
}©leetcode
