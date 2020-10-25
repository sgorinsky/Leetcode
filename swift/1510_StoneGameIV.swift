class Solution {
    func winnerSquareGame(_ n: Int) -> Bool {
        var dp = [false]
        var squares = [1]
        for i in 1...n {
            var root = Double(i).squareRoot()
            if root == floor(root) {
                dp.append(true)
                squares.append(i)
                continue
            }
            for square in squares {
                if dp[i-square] == false {
                    dp.append(true)
                    break
                }
            }
            if dp.count == i {
                dp.append(false)
            }
        }
        return dp[n]
    }
}
