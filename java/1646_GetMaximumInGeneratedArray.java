class Solution {
    public int getMaximumGenerated(int n) {
        if (n <= 0) return 0;
        
        int[] dp = new int[n+1];
        dp[1] = 1;
        
        int high = 0;
        for (int i = 0; i <= n; ++i) {
            dp[i] = i% 2 == 0 ? dp[i / 2] : dp[i / 2] + dp[i / 2 + 1];
            high = Math.max(high, dp[i]);
        }
        return high;
    }
}
