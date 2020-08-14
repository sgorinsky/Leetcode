class Solution {
    var nums: [Int]
    init(_ nums: [Int]) {
        self.nums = nums
    }
    
    func pick(_ target: Int) -> Int {
        var rand: Int
        var randIdx = nums.startIndex
        repeat {
            rand = Int.random(in: 0..<nums.count)
            randIdx = nums.index(nums.startIndex, offsetBy: rand)
        } while nums[randIdx] != target
        return rand
    }
}
