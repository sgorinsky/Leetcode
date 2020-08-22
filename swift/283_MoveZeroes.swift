class Solution {
    func moveZeroes(_ nums: inout [Int]) {
        var trailIdx = nums.index(nums.startIndex, offsetBy: 0)
        var headIdx = trailIdx
        
        while headIdx != nums.endIndex {
            if nums[headIdx] != 0 {
                var temp = nums[trailIdx]
                nums[trailIdx] = nums[headIdx]
                nums[headIdx] = temp
                nums.formIndex(after: &trailIdx)
            }
            nums.formIndex(after: &headIdx)
        }
    }
}
