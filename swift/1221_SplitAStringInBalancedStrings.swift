class Solution {
    func balancedStringSplit(_ s: String) -> Int {
        var score: Int = 0
        var count: Int = 0
        for c in s {
            score += c == "L" ? 1 : -1
            if score == 0 {
                count += 1
            }
        }
        return count
    }
}
