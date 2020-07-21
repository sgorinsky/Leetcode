class Solution {
public:
    bool isPossible = false;
    // Making visited a class property since there was a memory overflow when passing visited down to check i believe
    // runtime error: addition of unsigned offset to 0x608000000020 overflowed to 0x608000000008 (stl_vector.h)
    vector<vector<bool>> visited; 
    
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        this->visited = visited;
        
        // Another way of initializing this->visited:
        // for (int i = 0; i < board.size(); ++i) {
        //     this->visited.push_back({});
        //     for (int j = 0; j < board[0].size(); ++j) {
        //         this->visited[i].push_back(false);
        //     }
        // }    
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                check(i, j, 0, board, word);
                if (this->isPossible) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool check(int i, int j, int idx, vector<vector<char>>& board, string word) {
        if (this->visited[i][j] || board[i][j] != word[idx]) {
            return false;
        } else if (idx == word.length()-1 and board[i][j] == word[idx]) {
            this->isPossible = true;
            return true;
        }
        if (!this->visited[i][j] and !this->isPossible) {
            this->visited[i][j] = true;
            if (i > 0 && board[i-1][j] == word[idx+1]) {
                check(i-1, j, idx+1, board, word);
            }
            if (j > 0 && board[i][j-1] == word[idx+1]) {
                check(i, j-1, idx+1, board, word);
            }
            if (i < board.size()-1 && board[i+1][j] == word[idx+1]) {
                check(i+1, j, idx+1, board, word);
            }
            if (j < board[0].size()-1 && board[i][j+1] == word[idx+1]) {
                check(i, j+1, idx+1, board, word);
            }
            this->visited[i][j] = false;
        }
        return this->isPossible;
    }
};
