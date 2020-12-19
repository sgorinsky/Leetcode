class Solution {
    func increasingTriplet(_ nums: [Int]) -> Bool {
        if nums.isEmpty { return false }
        
        var stacks = [[nums[0]]]
        for i in 1..<nums.count {
            var n = nums[i]
            for j in 0..<stacks.count {
                var stackLength = stacks[j].count
                if n < stacks[j].last! && (stacks[j].count == 1 || stacks[j][0] < n) {
                    stacks[j][stackLength - 1] = n
                    break
                } else if n < stacks[j][0] && j == stacks.count - 1 {
                    stacks.append([n])
                    break
                } else if n > stacks[j].last! {
                    stacks[j].append(n)
                    if stacks[j].count == 3 { return true }
                    break
                }
            }
        }
        return false;
    }
}
