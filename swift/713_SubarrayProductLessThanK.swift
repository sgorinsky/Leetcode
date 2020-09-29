class Solution {
    func numSubarrayProductLessThanK(_ nums: [Int], _ k: Int) -> Int {
        var count: Int = 0, trailIdx: Int = 0
        var currProduct: Int = 1

        for (i, n) in nums.enumerated() {
            currProduct *= n
            while currProduct >= k && trailIdx <= i {
                currProduct /= nums[trailIdx]
                trailIdx += 1
            }
            count += (i - trailIdx + 1)
        }
        return count
    }
}
