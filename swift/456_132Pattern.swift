class Solution {
    func find132pattern(_ nums: [Int]) -> Bool {
        if nums.count < 3 { return false }
        
        var minNumAtI = Int.max
        var minNums = [Int]()
        for n in nums {
            minNumAtI = min(n, minNumAtI)
            minNums.append(minNumAtI)
        }
        
        var stack = [Int]()
        for j in stride(from: nums.count-1, through: 0, by: -1) {
            if minNums[j] < nums[j] {
                while !stack.isEmpty && stack.last! <= minNums[j] { stack.removeLast() }
                if !stack.isEmpty && stack.last! < nums[j] { return true }
                stack.append(nums[j])
            }
        }
        return false
    }
}
