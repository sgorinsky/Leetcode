class Solution {
    func climbStairs(_ n: Int) -> Int {
        if n <= 1 { return 1 }
        var stairs = [Int](repeating: 1, count: n + 1)
        for i in 2...n {
            stairs[i] = stairs[i - 1] + stairs[i - 2]
        }
        return stairs[n]
    }
}
