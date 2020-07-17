class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        lowest, highest, profit = 1000000, -1000000, 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i-1]:
                profit += prices[i] - prices[i-1]
        return profit
