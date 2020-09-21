class Solution {
public:
    vector<vector<bool>> checked;
    int total_zeroes, count; 
    pair<int, int> start, end;
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        total_zeroes = 0;
        int num_rows = grid.size(), num_cols = grid[0].size();
        
        for (int i = 0; i < num_rows; ++i) {
            checked.push_back({});
            for (int j = 0; j < num_cols; ++j) {
                if (grid[i][j] == 0) total_zeroes++;
                else if (grid[i][j] == 1) start = {i, j};
                else if (grid[i][j] == 2) end = {i, j};
                checked[i].push_back(false);
            }
        }
        count = 0;
        
        return check(start.first, start.second, 0, grid);
    }
    
    int check(int row, int col, int zeroes, vector<vector<int>>& grid) {
        if (end == pair<int, int>{row, col}) {
            if (zeroes == total_zeroes) count++;
            return count;
        }
    
        if (grid[row][col] == 0) zeroes++;

        checked[row][col] = true;
        for (pair<int, int> direction : directions) {
            if (can_go(row, col, direction, grid))
                check(row + direction.first, col + direction.second, zeroes, grid);
        }
        checked[row][col] = false;
        return count;
    }
    
    bool can_go(int row, int col, pair<int, int>& direction, vector<vector<int>>& grid) {
        int cand_row = row + direction.first, cand_col = col + direction.second;
        return cand_row >= 0  && cand_row < checked.size() && cand_col >= 0 && cand_col < checked[0].size() && grid[cand_row][cand_col] != -1 && !checked[cand_row][cand_col];
    }
};
