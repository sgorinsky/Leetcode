class Solution {
    func flipAndInvertImage(_ matrix: [[Int]]) -> [[Int]] {
        var A = matrix
        for i in 0..<A.count {
            var left = 0, right = A[0].count - 1
            while left <= right {
                var temp = A[i][left]
                A[i][left] = A[i][right] ^ 1
                A[i][right] = temp ^ 1
                left += 1
                right -= 1
            }
        }
        return A
    }
}
