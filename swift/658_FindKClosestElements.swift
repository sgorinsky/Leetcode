class Solution {
    func findClosestElements(_ arr: [Int], _ k: Int, _ x: Int) -> [Int] {
        var left = 0, right = arr.count - k
        while left < right {
            var mid = left + (right - left) / 2
            if x - arr[mid] <= arr[mid + k] - x { right = mid }
            else { left = mid + 1 }
        }
        return [Int](arr[left..<left+k])
    }
}
