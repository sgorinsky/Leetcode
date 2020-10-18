class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        N = len(prices)
        if 2*k >= N:
            profit = 0
            for i in range(1, N):
                profit += max(0, prices[i] - prices[i-1])
            return profit
        
        dp = [[0 for j in range(N)] for i in range(k+1)]
        for i in range(1, k+1):
            max_profit = -prices[0]
            for j in range(1, N):
                dp[i][j] = max(dp[i][j-1], max_profit + prices[j])
                max_profit = max(dp[i-1][j] - prices[j], max_profit)
        
        return dp[k][N-1]
