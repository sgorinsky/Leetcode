class Solution {
    func canPartition(_ nums: [Int]) -> Bool {
        var total = 0
        var N = nums.count
        for n in nums {
            total += n
        }
        if total % 2 != 0 { return false } 
        
        total /= 2
        var dp = [[Bool]](repeating: [Bool](repeating: false, count: total + 1), count: N + 1)
        dp[0][0] = true
        
        for i in 1...N {
            var currentNumber = nums[i - 1]
            for j in 0...total {
                dp[i][j] = dp[i - 1][j] || (j >= currentNumber && dp[i - 1][j - currentNumber])
            }
        }
        return dp[N][total]
    }
}
