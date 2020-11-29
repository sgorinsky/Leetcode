class Solution {
    func mostCompetitive(_ nums: [Int], _ k: Int) -> [Int] {
        var stack = [Int]()
        var i = 0
        var N = nums.count
        while i < N {
            var num = nums[i]
            while !stack.isEmpty && N - i + stack.count > k && num < stack.last! {
                stack.removeLast()
            }
            stack.append(num)
            i += 1
        }
        while stack.count > k {
            stack.removeLast()
        }
        return stack
    }
}
