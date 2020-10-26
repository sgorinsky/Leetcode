class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    islands++;
                    clearIslands(grid, i, j);
                }
            }
        }
        return islands;
    }
    
    void clearIslands(vector<vector<char>>& grid, int i, int j) {
        vector<pair<int, int>> stack = {{i, j}};
        while (!stack.empty()) {
            pair<int, int> curr = stack.back();
            stack.pop_back();
            
            i = curr.first;
            j = curr.second;
            grid[i][j] = '2';
            
            for (pair<int, int> direction : directions) {
                int r = i + direction.first;
                int c = j + direction.second;
                if (canTraverseTo(grid, r, c)) {
                    stack.push_back({r, c});
                }
            }
        }
    }
    
    bool canTraverseTo(vector<vector<char>>& grid, int i, int j) {
        return i >= 0 && i < grid.size() &&
            j >= 0 && j < grid[0].size() &&
            grid[i][j] == '1';
    }
};

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
