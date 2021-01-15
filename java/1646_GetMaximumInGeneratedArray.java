class Solution {
    public int getMaximumGenerated(int n) {
        if (n <= 0) return 0;
        
        int[] dp = new int[n+1];
        dp[1] = 1;
        
        int high = 0;
        for (int i = 0; i <= n; ++i) {
            dp[i] = dp[i / 2] + (i % 2 == 1 ? dp[i / 2 + 1] : 0);
            high = Math.max(high, dp[i]);
        }
        return high;
    }
}
