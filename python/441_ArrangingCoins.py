class Solution:
    def arrangeCoins(self, n: int) -> int:
        if n < 0:
            return -1
        k, count = 1, 0
        while n > 0:
            if k <= n:
                count += 1
            n -= k
            k += 1
        return count
