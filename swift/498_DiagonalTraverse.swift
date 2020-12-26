class Solution {
    func findDiagonalOrder(_ matrix: [[Int]]) -> [Int] {
        var diagonals = [Int]()
        if matrix.isEmpty || matrix[0].isEmpty {
            return diagonals
        }
        
        var N = matrix.count, M = matrix[0].count
        var up = true
        var i = 0, j = 0
        for idx in 0..<N * M {
            diagonals.append(matrix[i][j])
            if up {
                if j == M - 1 {
                    i += 1
                    up = false
                } else if i == 0 {
                    j += 1
                    up = false
                } else {
                    i -= 1
                    j += 1
                }
            } else {
                if i == N - 1 {
                    j += 1
                    up = true
                } else if j == 0 {
                    i += 1
                    up = true
                } else {
                    i += 1
                    j -= 1
                }
            }
        }
        return diagonals
    }
}
