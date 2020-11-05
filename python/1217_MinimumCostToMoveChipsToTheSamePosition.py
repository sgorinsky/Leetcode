class Solution:
    def minCostToMoveChips(self, positions: List[int]) -> int:
        evens = odds = 0
        for p in positions:
            if p % 2: odds += 1
            else: evens += 1
        return min(odds, evens)
