class Solution {
    func findMaxConsecutiveOnes(_ nums: [Int]) -> Int {
        var left: Int = 0, lastZero: Int = -1, high: Int = 0, N: Int = nums.count
        
        for (i, element) in nums.enumerated() {
            if element == 0 {
                if lastZero >= 0 { 
                    left = lastZero + 1 
                }
                lastZero = i
            }
            high = max(high, i - left + 1)
        }
        return high
    }
}
