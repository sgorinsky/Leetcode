class Solution {
    func smallestDivisor(_ nums: [Int], _ threshold: Int) -> Int {
        func computeSum(_ divisor: Int) -> Int {
            var total = 0
            for n in nums {
                total += n / divisor + (n % divisor != 0 ? 1 : 0)
            }
            return total            
        }
        
        var left = 1, right = 2
        while computeSum(right) > threshold {
            left = right
            right <<= 1
        }
        
        while left <= right {
            var pivot = left + (right - left) / 2
            var total = computeSum(pivot)
            if total > threshold {
                left = pivot + 1
            } else {
                right = pivot - 1
            }
        }
        return left
    }
}
