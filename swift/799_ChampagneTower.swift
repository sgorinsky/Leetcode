class Solution {
    func champagneTower(_ poured: Int, _ query_row: Int, _ query_glass: Int) -> Double {
        var dp = [[Double]](repeating: [Double](repeating: 0.0, count: query_row + 1), count: query_row + 1)
        dp[0][0] = Double(poured)
        for i in 0...query_row {
            for j in 0...query_row {
                if i == 0 || j > i {
                    break
                } else if j == 0 {
                    dp[i][j] = max(0, (dp[i-1][j] - 1) / 2.0)
                } else if j == i {
                    dp[i][j] = max(0, (dp[i-1][j-1] - 1) / 2.0) 
                } else {
                    dp[i][j] = max(0, (dp[i-1][j-1] - 1) / 2.0) + max(0, (dp[i-1][j] - 1) / 2.0)
                }
            }
        }
        return min(1.0, dp[query_row][query_glass])
    }
}
