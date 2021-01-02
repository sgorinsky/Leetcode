class Solution {
    func gameOfLife(_ board: inout [[Int]]) {
        func changeBoardEntry(_ count: Int, _ i: Int, _ j: Int) {
            if board[i][j] == 0 {
                if count == 3 {
                    board[i][j] = 2
                }
            } else if count < 2 || count > 3  {
                board[i][j] = -1
            }
        }
        
        func countNeighbors(_ i: Int, _ j: Int) -> Int {
            var count = 0
            if i > 0 { 
                count += abs(board[i-1][j]) % 2 
                if j > 0 {
                    count += abs(board[i-1][j-1]) % 2
                }
                if j < N - 1 {
                    count += abs(board[i-1][j+1]) % 2
                }
            }
            if i < M - 1 { 
                count += abs(board[i+1][j]) % 2
                if j > 0 {
                    count += abs(board[i+1][j-1]) % 2
                }
                if j < N - 1 {
                    count += abs(board[i+1][j+1]) % 2
                }
            }
            
            if j > 0 { count += abs(board[i][j-1]) % 2 }
            if j < N - 1 { count += abs(board[i][j+1]) % 2}
            
            return count
        }
        
        var M = board.count, N = board[0].count
        for i in 0..<M {
            for j in 0..<N {
                var count = countNeighbors(i, j)
                changeBoardEntry(count, i, j)
            }
        }
        
        for i in 0..<M {
            for j in 0..<N {
                if board[i][j] == -1 {
                    board[i][j] = 0
                } else if board[i][j] == 2 {
                    board[i][j] = 1
                }
            }
        }
    }
}
