class Solution {
    func searchRange(_ nums: [Int], _ target: Int) -> [Int] {
        func boundsSearch(_ findLeftBound: Bool) -> Int {
            var left = 0, right = nums.count
            while left < right {
                var mid = left + (right - left) / 2
                if nums[mid] > target || (findLeftBound && nums[mid] == target) {
                    right = mid
                } else {
                    left = mid + 1
                }
            }
            return left
        }
        
        var leftBound = boundsSearch(true)
        if leftBound == nums.count || nums[leftBound] != target { return [-1, -1] }
        return [leftBound, boundsSearch(false) - 1]
    }
}
