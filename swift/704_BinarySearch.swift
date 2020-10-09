class Solution {
    func search(_ nums: [Int], _ target: Int) -> Int {
        var left = 0, right = nums.count - 1
        while left <= right {
            var mid = (left + right) >> 1
            if nums[mid] == target { return mid }
            else if (nums[mid] < target) { left = mid + 1}
            else { right = mid - 1}
        }
        return -1
    }
}
