class Solution {
    func maxProduct(_ nums: [Int]) -> Int {
        var N = nums.count
        if N == 0 { return 0 }
        var max: Int = nums[0], min: Int = max, high: Int = max
        for i in 1..<N {
            var curr: Int = nums[i]
            var temp: Int = findMax(max * curr, min * curr, curr)
            min = findMin(max * curr, min * curr, curr)
            max = temp
            high = findMax(high, max)
        }
        return high
    }
    
    func findMax(_ nums: Int...) -> Int {
        var high = -10000000
        for n in nums {
            high = n > high ? n : high
        }
        return high
    }
    
    func findMin(_ nums: Int...) -> Int {
        var low = 10000000
        for n in nums {
            low = n < low ? n : low
        }
        return low
    }
}
