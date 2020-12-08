class Solution {
    func spiralOrder(_ matrix: [[Int]]) -> [Int] {
        var i = 0, j = 0, m = matrix.count, n = matrix[0].count
        var direction = 0
        var rowStart = 1, rowSize = m - 1, colStart = 0, colSize = n - 1
        
        var spiralEntries = [Int]()
        for x in 0..<m * n {
            spiralEntries.append(matrix[i][j])
            if direction == 0 {
                if j == colSize {
                    i += 1
                    colSize -= 1
                    direction = (direction + 1) % 4
                } else {
                    j += 1
                }
            } else if direction == 1 {
                if i == rowSize {
                    j -= 1
                    rowSize -= 1
                    direction = (direction + 1) % 4
                } else {
                    i += 1
                }
            } else if direction == 2 {
                if j == colStart {
                    i -= 1
                    colStart += 1
                    direction = (direction + 1) % 4
                } else {
                    j -= 1
                }
            } else {
                if i == rowStart {
                    j += 1
                    rowStart += 1
                    direction = (direction + 1) % 4
                } else {
                    i -= 1
                }
            }
        }
        return spiralEntries
    }
}
