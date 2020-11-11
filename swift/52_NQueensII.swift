class Solution {
    func totalNQueens(_ n: Int) -> Int {
        var rows = [Int](repeating: 0, count: n)
        var hills = [Int](repeating: 0, count: 4 * n - 1)
        var dales = [Int](repeating: 0, count: 2 * n - 1)
        
        func checkAndPlaceQueens(_ row: Int, _ count: Int) -> Int {
            var currentCount = count
            for c in 0..<n {
                if safePosition(row, c) {
                    addQueenToBoards(row, c)
                    if row + 1 == n {
                        currentCount += 1
                    } else {
                        currentCount = checkAndPlaceQueens(row + 1, currentCount)
                    }
                    removeQueenFromBoards(row, c)
                }
            }
            return currentCount
        }
        
        func addQueenToBoards(_ row: Int, _ col: Int) {
            rows[col] = 1
            hills[row - col + 2 * n] = 1
            dales[row + col] = 1
        }
        
        func removeQueenFromBoards(_ row: Int, _ col: Int) {
            rows[col] = 0
            hills[row - col + 2 * n] = 0
            dales[row + col] = 0
        }
        
        func safePosition(_ row: Int, _ col: Int) -> Bool {
            return rows[col] == 0 && hills[row - col + 2 * n] == 0 && dales[row + col] == 0
        }
        
        return checkAndPlaceQueens(0, 0)
    }
}
