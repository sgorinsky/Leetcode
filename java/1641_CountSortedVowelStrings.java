class Solution {
    func countVowelStrings(_ n: Int) -> Int {
        var dp = [[Int]](repeating: [Int](repeating: 1, count: 5), count: n + 1)
        for i in 1...n {
            for j in 1..<5 {
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
            }
        }
        return dp[n][4]
    }
}
