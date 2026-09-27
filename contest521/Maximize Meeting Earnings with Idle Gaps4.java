class Solution {
    public long maxEarnings(int[][] meetings) {
       Arrays.sort(meetings, (a,b) -> Integer.compare(a[1], b[1]));

        int n = meetings.length;
        long[] dp = new long[n];
        long[] best = new long[n];

        for(int i = 0; i<n;i++){
            int start = meetings[i][0];
            int end = meetings[i][1];
            int revenue = meetings[i][2];

            dp[i] = revenue;

            int lo = 0, hi = i-1;
            int prev = -1;

            while(lo <= hi){
                int mid = lo + (hi - lo)/2;
                if(meetings[mid][1] <= start){
                    prev = mid;
                    lo = mid+1;
                } else {
                    hi = mid - 1;
                }
            }
            if(prev != -1){
                dp[i] = Math.max(
                    dp[i],
                    best[prev] + start + revenue
                );
            }
            long value = dp[i] - end;
            if(i==0){
                best[i] = value;
            } else {
                best[i] = Math.max(best[i-1], value);
            }
        }
        long ans = 0;
        for(long x : dp){
            ans = Math.max(ans, x);
        }
        return ans;
    }
}