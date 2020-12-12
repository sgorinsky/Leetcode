class Solution {
    func removeDuplicates(_ nums: inout [Int]) -> Int {
        if nums.isEmpty { return 0 }
        var count = 1, j = 1
        for i in 1..<nums.count {
            count = nums[i] == nums[i-1] ? count + 1 : 1
            if count < 3 {
                nums[j] = nums[i]
                j += 1
            }
        }
        return j
    }
}
