class Solution {
    func maxProfit(_ k: Int, _ prices: [Int]) -> Int {
        var N = prices.count
        if N <= 1 || k == 0 { return 0 }
        if 2*k >= N {
            var profit = 0
            for i in 1..<N {
                profit += max(0, prices[i] - prices[i-1])
            }
            return profit
        }

        var dp = [[Int]](repeating: [Int](repeating: 0, count: N), count: k + 1)
        for i in 1...k {
            var runningProfit = -prices[0]
            for j in 1..<N {
                dp[i][j] = max(dp[i][j-1], runningProfit + prices[j])
                runningProfit = max(runningProfit, dp[i-1][j] - prices[j])
            }
        }
        return dp[k][N-1]
    }
}
