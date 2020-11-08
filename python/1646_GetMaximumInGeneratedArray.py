class Solution:
    def getMaximumGenerated(self, n: int) -> int:
        if n <= 0: return 0
        dp = [0 for _ in range(n + 1)]
        high = dp[1] = 1
        for i in range(n + 1):
            dp[i] = dp[i // 2] if i % 2 == 0 else dp[i // 2] + dp[i // 2 + 1]
            high = max(high , dp[i])
        return high
