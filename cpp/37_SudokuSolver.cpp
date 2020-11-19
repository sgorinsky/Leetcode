class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
    
    bool checkEntry(vector<vector<char>>& board, char cand, int row, int col) {
        int box_row = row / 3 * 3, box_col = col / 3 * 3;
        for (int i = 0; i < 9; ++i) {
            if (row != i && board[i][col] == cand) return false;
            if (col != i && board[row][i] == cand) return false;
            if ((box_row != row && box_col != col) && board[box_row][box_col] == cand) return false;
            
            box_row = row / 3 * 3 + i / 3;
            box_col = col / 3 * 3 + i % 3;
        }
        return true;
    }
    
    bool backtrack(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (int n = 1; n <= 9; ++n) {
                        char cand = '0' + n;
                        if (checkEntry(board, cand, i, j)) {
                            board[i][j] = cand;
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
};
