class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        high = 0
        for account in accounts:
            high = max(high, sum(account))
        return high
