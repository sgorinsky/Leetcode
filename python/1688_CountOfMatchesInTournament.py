class Solution:
    def numberOfMatches(self, n: int) -> int:
        total = 0
        while n >= 2:
            total += n // 2
            n -= n // 2
        return total
