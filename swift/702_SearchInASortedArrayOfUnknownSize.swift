/**
 * // This is ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * public class ArrayReader {
 *     public func get(_ index: Int) -> Int {}
 * }
 */

class Solution {
    func search(_ reader: ArrayReader, _ target: Int) -> Int {
        if reader.get(0) == target { return 0 }
        
        var left = 0, right = 1
        while reader.get(right) < target {
            left = right
            right <<= 1
        }
        
        while left <= right {
            var mid = left + (right - left) / 2
            var num = reader.get(mid)
            
            if num == target { return mid }
            else if num > target { right = mid - 1 }
            else { left = mid + 1 }
        }
        return -1
    }
}
