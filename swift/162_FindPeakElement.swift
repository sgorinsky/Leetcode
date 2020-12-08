class Solution {
    func findPeakElement(_ nums: [Int]) -> Int {
        func binarySearch(_ left: Int, _ right: Int) -> Int {
            if left == right { return left }
            
            var mid = left + (right - left) / 2
            return nums[mid] > nums[mid + 1] ? binarySearch(left, mid) : binarySearch(mid + 1, right)
        }
        
        return binarySearch(0, nums.count - 1)
    }
}
