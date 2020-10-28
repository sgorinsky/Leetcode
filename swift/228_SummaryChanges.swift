class Solution {
    func summaryRanges(_ nums: [Int]) -> [String] {
        var results = [String]()
        if nums.isEmpty { return results }
        var low = nums[0], high = nums[0]
        for n in nums {
            if n > high + 1 {
                results += [low == high ? "\(low)" : "\(low)->\(high)"]
                low = n
                high = n
            } else {
                high = n
            }
        }
        return results + [low == high ? "\(low)" : "\(low)->\(high)"]
    }
}
