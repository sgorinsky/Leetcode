class Solution:
    def wordBreak(self, s, wordDict):
        wordSet = set(wordDict)
        n = len(s)
        dp = [0] * n + [1]
        
        for i in range(n):
            for j in range(i+1):
                if s[j:i+1] in wordSet:
                    dp[i] = max(dp[i], dp[j-1])
        return dp[-2] > 0
