class Solution {
    func diagonalSort(_ mat: [[Int]]) -> [[Int]] {
        func storeAndSortDiagonal(_ row: Int, _ col: Int) {
            var i = row, j = col
            var diagonal = [Int]()
            while i < N && j < M {
                diagonal.append(A[i][j])
                i += 1
                j += 1
            }
            
            diagonal = diagonal.sorted() { $0 < $1 }
            i = row
            j = col
            for n in diagonal {
                A[i][j] = n
                i += 1
                j += 1
            }
        }
        
        var A = mat
        var N = A.count, M = A[0].count
        for i in 0..<N {
            storeAndSortDiagonal(i, 0)
        }
        
        for j in 0..<M {
            storeAndSortDiagonal(0, j)
        }
        
        return A
    }
}
