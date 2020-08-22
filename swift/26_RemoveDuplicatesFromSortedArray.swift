class Solution {
    func removeDuplicates(_ nums: inout [Int]) -> Int {
        if nums.isEmpty { return 0 }
        
        var length = 1
        var leftIdx = nums.index(nums.startIndex, offsetBy: 1)
        var rightIdx = leftIdx
        
        while rightIdx != nums.endIndex {
            if (nums[leftIdx] <= nums[nums.index(leftIdx, offsetBy: -1)]) {
                while rightIdx != nums.endIndex && nums[rightIdx] <= nums[nums.index(rightIdx, offsetBy: -1)] {
                    nums.formIndex(after: &rightIdx)
                }
                
                if rightIdx != nums.endIndex && nums[rightIdx] > nums[nums.index(rightIdx, offsetBy: -1)] {
                    nums[leftIdx] = nums[rightIdx]
                    nums.formIndex(after: &leftIdx)
                    nums.formIndex(after: &rightIdx)
                    length += 1
                }
            } else {
                nums.formIndex(after: &leftIdx)
                nums.formIndex(after: &rightIdx)
                length += 1
            }
        }
        return length
    }
}
