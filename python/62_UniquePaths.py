class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        if m == 1 or n == 1:
            return 1
        dp = [[0 for _ in range(m)] for _ in range(n)]
        
        for i in range(n):
            for j in range(m):
                if i > 0 and j > 0:
                    dp[i][j] += dp[i-1][j] + dp[i][j-1]
                elif i > 0:
                    dp[i][j] = 1
                elif j > 0:
                    dp[i][j] = 1

        return dp[-1][-1]

class Solution:
    cache = {(0,0): 1, (1,1): 1}
    def uniquePaths(self, x: int, y: int) -> int:
        if x <= 0 or y <= 0:
            self.cache[(x, y)] = 0
            return 0
        elif (x, y) in self.cache:
            return self.cache[(x, y)]
        elif (y, x) in self.cache:
            return self.cache[(y, x)]
        else:
            self.cache[(x, y)] = self.uniquePaths(x-1, y) + self.uniquePaths(x, y-1)
            return self.cache[(x, y)]
