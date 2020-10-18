class Solution {
    public int maxProfit(int k, int[] prices) {
        int N = prices.length;
        if (k >= N/2) {
            int profit = 0;
            for (int i = 1; i < prices.length; ++i) profit += Math.max(prices[i] - prices[i-1], 0);
            return profit;
        }
        
        int[][] dp = new int[k+1][N];
        for (int i = 1; i <= k; ++i) {
            int profit = -prices[0];
            for (int j = 1; j < N; ++j) {
                dp[i][j] = Math.max(dp[i][j-1], profit + prices[j]);
                profit = Math.max(dp[i-1][j] - prices[j], profit);
            }
        }
        return dp[k][N-1];
    }
}
