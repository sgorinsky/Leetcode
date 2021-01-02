class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int count = live_count(board, i, j);
                convert_entry(board, board[i][j], i, j, count);
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 2) {
                    board[i][j] = 1;
                } else if (board[i][j] == -1) {
                    board[i][j] = 0;
                }
            }
        }
    }
    
    void convert_entry(vector<vector<int>>& board, int entry, int i, int j, int count) {
        if (entry == 0) {
            if (count == 3) board[i][j] = 2;
        } else if (count < 2 || count > 3) {
            board[i][j] = -1;
        }
    }
    
    int live_count(vector<vector<int>>& board, int i, int j) {
        int count = 0;
        // cardinals
        if (i > 0) count += abs(board[i - 1][j]) % 2;
        if (i < board.size() - 1) count += abs(board[i + 1][j]) % 2;
        if (j > 0) count += abs(board[i][j - 1]) % 2;
        if (j < board[0].size() - 1) count += abs(board[i][j + 1]) % 2;
        
        // diagonals
        if (i > 0 && j > 0) count += abs(board[i - 1][j - 1]) % 2;
        if (i > 0 && j < board[0].size() - 1) count += abs(board[i - 1][j + 1]) % 2;
        if (i < board.size() - 1 && j > 0) count += abs(board[i + 1][j - 1]) % 2;
        if (i < board.size() - 1 && j < board[0].size() - 1) count += abs(board[i + 1][j + 1]) % 2;
        
        return count;
    }
};

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> new_board(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int count = live_count(board, i, j);
                convert_entry(new_board, board[i][j], i, j, count);
            }
        }
        board = new_board;
    }
    
    void convert_entry(vector<vector<int>>& board, int entry, int i, int j, int count) {
        if (entry == 0) {
            if (count == 3) board[i][j] = 1;
        } else {
            board[i][j] = count < 2 || count > 3 ? 0 : 1;
        }
    }
    
    int live_count(vector<vector<int>>& board, int i, int j) {
        int count = 0;
        // cardinals
        if (i > 0) count += board[i - 1][j];
        if (i < board.size() - 1) count += board[i + 1][j];
        if (j > 0) count += board[i][j - 1];
        if (j < board[0].size() - 1) count += board[i][j + 1];
        
        // diagonals
        if (i > 0 && j > 0) count += board[i - 1][j - 1];
        if (i > 0 && j < board[0].size() - 1) count += board[i - 1][j + 1];
        if (i < board.size() - 1 && j > 0) count += board[i + 1][j - 1];
        if (i < board.size() - 1 && j < board[0].size() - 1) count += board[i + 1][j + 1];
        
        return count;
    }
};
