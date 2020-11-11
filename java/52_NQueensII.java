class Solution {
    public int totalNQueens(int n) {
        if (n == 0) return 1;
        int[][] board = new int[n][n];
        
        int count = checkAndPlaceQueensOnBoard(board, 0, 0);
        return count;
    }
    
    public int checkAndPlaceQueensOnBoard(int[][] board, int row, int count) {
        for (int c = 0; c < board.length; ++c) {
            if (canPlaceQueenHere(board, row, c)) {
                board[row][c] = 1;
                if (row + 1 == board.length) {
                    count++;
                } else {
                    count = checkAndPlaceQueensOnBoard(board, row + 1, count);
                }
                board[row][c] = 0;
            }
        }
        return count;
    }
    
    public boolean canPlaceQueenHere(int[][] board, int row, int col) {
        if (row == board.length || row == 0) 
            return true;
        
        for (int i = 0; i <= row; ++i) {
            if (board[row-i][col] == 1 || 
               (col >= i && board[row-i][col-i] == 1) ||
               (col + i < board.length && board[row-i][col+i] == 1))
                return false;
        }
        
        return true;
    }
}
