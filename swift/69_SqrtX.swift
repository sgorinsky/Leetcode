class Solution {
    func mySqrt(_ x: Int) -> Int {
        if x == 1 { return 1 }
        var left = 1, right = x / 2
        while left <= right {
            var mid = left + (right - left) / 2
            var squared = mid * mid
            if squared == x { return mid }
            else if squared > x { right = mid - 1 }
            else { left = mid + 1 }
        }
        return right
    }
}

class Solution {
    func mySqrt(_ x: Int) -> Int {
        return Int(sqrt(Double(x)))
    }
}
