class Solution {
    func findTargetSumWays(_ nums: [Int], _ S: Int) -> Int {
        var dp = [Int](repeating: 0, count: 2001)
        dp[nums[0] + 1000] = 1
        dp[-nums[0] + 1000] += 1
        
        for i in 1..<nums.count {
            var next = [Int](repeating: 0, count: 2001)
            for sum in -1000...1000 {
                if dp[sum + 1000] > 0 {
                    next[sum + nums[i] + 1000] += dp[sum + 1000]
                    next[sum - nums[i] + 1000] += dp[sum + 1000]
                }
            }
            dp = next
        }
        return S > 1000 ? 0 : dp[S + 1000]
    }
}
