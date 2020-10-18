class Solution {
public:
    const vector<vector<int>> directions = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    
    void bfs(vector<vector<char>>& grid, int row, int col) {
        queue<vector<int>> q;
        q.push({row, col});
        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            
            int i = curr[0], j = curr[1];
            grid[i][j] = '2';
            for (vector<int> direction : directions) {
                int r = i + direction[0], c  = j + direction[1]; // next potential i, j
                if (can_go(grid, r, c)) {
                    grid[r][c] = '2';
                    q.push({r, c});
                }
            }
        }
    }
    
    bool can_go(vector<vector<char>>& grid, int i, int j) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == '1';
    }
};
