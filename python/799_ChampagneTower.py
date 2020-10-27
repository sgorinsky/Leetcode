class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        dp = [[0 for j in range(query_row+1)] for i in range(query_row+1)]
        dp[0][0] = poured
        for i in range(query_row+1):
            for j in range(query_row+1):
                if i == 0 or j > i: 
                    break
                elif j == 0:
                    dp[i][j] = max(0, dp[i-1][j] - 1) / 2.0
                elif j == i:
                    dp[i][j] = max(0, dp[i-1][j-1] - 1)  / 2.0
                else:
                    dp[i][j] = max(0, dp[i-1][j-1] - 1) / 2.0 + max(0, dp[i-1][j] - 1) / 2.0
        return min(1.0, dp[query_row][query_glass])
