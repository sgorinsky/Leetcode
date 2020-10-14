class Solution {
    func rob(_ nums: [Int]) -> Int {
        var N = nums.count
        if N == 1 { return nums[0] }
        func robPath(_ start: Int, _ end: Int) -> Int {
            var previousSum = 0, currentSum = 0
            for i in start...end {
                var temp = currentSum
                currentSum = max(previousSum + nums[i], currentSum)
                previousSum = temp
            }
            return currentSum
        }
        return max(robPath(0, N-2), robPath(1, N-1))
    }
}
