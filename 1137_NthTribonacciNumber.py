def tribonacci(num: int) -> int:
        memo = {0: 0, 1: 1, 2: 1}
        def trib(n):
            if n in memo:
                return memo[n]
            else:
                memo[n] = trib(n-1) + trib(n-2) + trib(n-3)
                return memo[n]
        return trib(num)

class Solution:
    memo = {0: 0, 1: 1, 2: 1}
    def tribonacci(self, n: int) -> int:
        if n in self.memo:
            return self.memo[n]
        else:
            self.memo[n] = self.tribonacci(n-1) + self.tribonacci(n-2) + self.tribonacci(n-3)
            return self.memo[n]
