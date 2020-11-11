class Solution {
public:
    int totalNQueens(int n) {
        if (n == 0) return 1;
        vector<vector<int>> board(n, vector<int>(n, 0));
        int count = checkAndPlaceQueen(board, 0, 0);
        return count;
    }
    
    int checkAndPlaceQueen(vector<vector<int>>& board, int row, int count) {
        for (int c = 0; c < board[0].size(); ++c) {
            if (notUnderAttack(board, row, c)) {
                board[row][c] = 1;
                if (row + 1 == board.size()) {
                    count++;
                } else {
                    count = checkAndPlaceQueen(board, row + 1, count);
                }
                board[row][c] = 0;
            }
        }
        return count;
    }
    
    bool notUnderAttack(vector<vector<int>>& board, int row, int col) {
        if (row == 0 || row >= board.size()) return true;
        
        for (int i = 0; i <= row; ++i) {
            if (board[row-i][col] == 1 || 
                (col >= i && board[row-i][col-i] == 1) || 
                (col + i < board.size() && board[row-i][col+i])) {
                return false;
            }
        }
        return true;
    }
};
