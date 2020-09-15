class Solution {
    func rob(_ nums: [Int]) -> Int {
        var prev: Int = 0, curr: Int = 0
        for n in nums {
            let temp: Int = curr
            curr = max(prev + n, curr)
            prev = temp
        }
        return curr
    }
}
