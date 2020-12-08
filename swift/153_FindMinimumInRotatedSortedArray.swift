class Solution {
    func findMin(_ nums: [Int]) -> Int {
        var left = 0, right = nums.count - 1
        while left < right {
            var mid = left + (right - left) / 2
            if nums[mid] < nums[right] { right = mid }
            else { left = mid + 1 }
        }
        return nums[left]
    }
}
