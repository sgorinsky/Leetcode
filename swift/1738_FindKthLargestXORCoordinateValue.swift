class Solution {
    func kthLargestValue(_ matrix: [[Int]], _ k: Int) -> Int {
        var xorValues = [Int]()
        var dp = matrix
        var N = dp.count, M = dp[0].count
        for i in 0..<N {
            for j in 0..<M {
                dp[i][j] ^= (i > 0 ? dp[i-1][j] : 0) ^ (j > 0 ? dp[i][j-1] : 0)
                xorValues.append(dp[i][j])
                if i < N - 1 && j < M - 1 {
                    dp[i+1][j+1] ^= dp[i][j]
                }
            }
        }
        xorValues = xorValues.sorted() { $0 > $1 }
        return xorValues[k - 1]
    }
}
