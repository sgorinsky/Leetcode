class Solution {
    func rotate(_ nums: inout [Int], _ k: Int) {
        let N = nums.count, jump = k % N
        if jump == 0 { return }
        
        var start = 0, count = 0
        while count < N {
            var currentIteration = start, previousNum = nums[start]
            repeat {
                var next = (start + jump) % N, temp = nums[next]
                nums[next] = previousNum
                previousNum = temp
                start = next
                count += 1
            } while start != currentIteration
            start += 1
        }
    }
}
