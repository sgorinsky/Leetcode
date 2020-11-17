class Solution {
    func solveSudoku(_ board: inout [[Character]]) {
        func checkCandidate(_ candidate: Character, _ row: Int, _ col: Int) -> Bool {
            var rowInBox = row / 3 * 3
            var colInBox = col / 3 * 3
            for i in 0..<9 {
                if i != col && board[row][i] == candidate {
                    return false
                }
                if i != row && board[i][col] == candidate {
                    return false
                }
                if rowInBox != row && colInBox != col && board[rowInBox][colInBox] == candidate {
                    return false
                }
                rowInBox = row / 3 * 3 + i / 3
                colInBox = col / 3 * 3 + i % 3
            }
            return true
        }
        
        func backtrack(_ isComplete: Bool) -> Bool {
            var checkIfComplete = isComplete
            for i in 0..<9 {
                for j in 0..<9 {
                    if board[i][j] == "." {
                        for n in 1...9 {
                            var c = Character("\(n)")
                            if checkCandidate(c, i, j) {
                                board[i][j] = c
                                checkIfComplete = backtrack(checkIfComplete)
                                if !checkIfComplete {
                                    board[i][j] = "."
                                } else {
                                    return true
                                }
                            }
                        }
                       return false
                    }
                }
            }
            return true
        }
        backtrack(false)
    }
}
