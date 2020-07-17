class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        lowest, highest, profit = 1000000, -1000000, 0
        for p in prices:
            if p < lowest:
                lowest = p
            elif p - lowest > profit:
                profit = p - lowest
        return profit
