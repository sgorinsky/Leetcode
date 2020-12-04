class Solution {
    func findMaxAverage(_ nums: [Int], _ k: Int) -> Double {
        var high = -10001.0, K = Double(k)
        var trailIdx = 0, sum = 0
        
        for (i, n) in nums.enumerated() {
            if i < k {
                sum += n
            } else {
                high = max(Double(sum) / K, high)
                sum = sum + n - nums[trailIdx]
                trailIdx += 1
            }
        }
        return max(Double(sum) / K, high)
    }
}
