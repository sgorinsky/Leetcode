class Solution:
    def numTrees(self, n: int) -> int:
        dp = [0] * (n+1)
        dp[0] = 1
        
        for i in range(1, n+1):
            for j in range(i):
                dp[i] += dp[j]*dp[i-1-j] # take complement of jth index up to where 0 <= j <= i-1
        return dp[n]
