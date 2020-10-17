class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<vector<int>> q;
        for (int i = 0; i < rooms.size(); ++i) {
            for (int j = 0; j < rooms[0].size(); ++j) {
                if (rooms[i][j] == 0) q.push({i, j});
            }
        }
        
        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            
            int i = curr[0], j = curr[1];
            for (vector<int> direction : directions) {
                int r = i + direction[0], c = j + direction[1];
                if (can_go(r, c, i, j, rooms)) {
                    rooms[r][c] = min(rooms[r][c], rooms[i][j] + 1);
                    q.push({r, c});
                }
            }
        }
    }
    
    // r, c are possible next row, col, i, j are prev
    bool can_go(int r, int c, int i, int j, vector<vector<int>>& rooms) {
        return r >= 0 && r < rooms.size() && c >= 0 && c < rooms[0].size() && rooms[r][c] > 0 && rooms[r][c] > rooms[i][j];
    }
};

class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void wallsAndGates(vector<vector<int>>& rooms) {
        for (int i = 0; i < rooms.size(); ++i) {
            for (int j = 0; j < rooms[0].size(); ++j) {
                if (rooms[i][j] == 0) {
                    bfs(rooms, i, j);
                }
            }
        }
    }
    
    void bfs(vector<vector<int>>& rooms, int row, int col) {
        queue<vector<int>> q;
        q.push({0, row, col});
        
        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            
            int i = curr[1], j = curr[2];
            rooms[i][j] = min(rooms[i][j], curr[0]);
            for (vector<int> direction : directions) {
                if (can_go(i + direction[0], j + direction[1], i, j, rooms))
                    q.push({rooms[i][j] + 1, i + direction[0], j + direction[1]});
            }
        }
    }
    
    bool can_go(int i, int j, int i_prior, int j_prior, vector<vector<int>>& rooms) {
        return i >= 0 && i < rooms.size() && j >= 0 && j < rooms[0].size() && rooms[i][j] > 0 && rooms[i][j] > rooms[i_prior][j_prior];
    }
};
