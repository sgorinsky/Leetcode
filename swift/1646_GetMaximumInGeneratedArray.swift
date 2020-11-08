class Solution {
    func getMaximumGenerated(_ n: Int) -> Int {
        if n <= 0 { return 0 }
        var dp = [Int](repeating: 0, count: n + 1)
        dp[1] = 1
        var high = 1
        
        for i in 0...n {
            dp[i] = i % 2 == 0 ? dp[i / 2] : dp[i / 2] + dp[i / 2] + 1
            high = max(high, dp[i])
        }
        return high
    }
}
