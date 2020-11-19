class Solution {
    public void solveSudoku(char[][] board) {
        backtrack(board);
    }
    
    public boolean isValidCandidate(char[][] board, char candidate, int row, int col) {
        int rowInBox = row / 3 * 3;
        int colInBox = col / 3 * 3;
        
        for (int i = 0; i < 9; ++i) {
            if (row != i && board[i][col] == candidate) return false;
            if (col != i && board[row][i] == candidate) return false;
            if ((rowInBox != row && colInBox != col) && board[rowInBox][colInBox] == candidate) return false;
            
            rowInBox = row / 3 * 3 + i / 3;
            colInBox = col / 3 * 3 + i % 3;
        }
        return true;
    }
    
    public boolean backtrack(char[][] board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (int n = 1; n <= 9; ++n) {
                        char candidate = (char) (n + '0');
                        if (isValidCandidate(board, candidate, i, j)) {
                            board[i][j] = candidate;
                            if (backtrack(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
}
