class Solution {
public:
    vector<vector<int> > updateMatrix(vector<vector<int> >& matrix) {
        int rows = matrix.size();
        if (rows == 0)
            return matrix;
        int cols = matrix[0].size();
        vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX));
        queue<pair<int, int> > q;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({ i, j }); //Put all 0s in the queue.
                }

        int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int new_r = curr.first + dir[i][0], new_c = curr.second + dir[i][1];
                if (new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols) {
                    if (dist[new_r][new_c] > dist[curr.first][curr.second] + 1) {
                        dist[new_r][new_c] = dist[curr.first][curr.second] + 1;
                        q.push({ new_r, new_c });
                    }
                }
            }
        }
        return dist;
    }
};

class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> updated_matrix = matrix;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                updated_matrix[i][j] = matrix[i][j] == 0 ? 0 : INT_MAX - 100;
            }
        }
        
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                for (vector<int> direction : directions) {
                    int r = i + direction[0], c = j + direction[1];
                    if (can_travel_to(updated_matrix, r, c)) {
                        updated_matrix[r][c] = min(updated_matrix[i][j] + 1, updated_matrix[r][c]);
                    }
                }
            }
        }
        
        for (int i = matrix.size() - 1; i >= 0; --i) {
            for (int j = matrix[0].size() - 1; j >= 0; --j) {
                for (vector<int> direction : directions) {
                    int r = i + direction[0], c = j + direction[1];
                    if (can_travel_to(updated_matrix, r, c)) {
                        updated_matrix[r][c] = min(updated_matrix[i][j] + 1, updated_matrix[r][c]);
                    }
                }
            }
        }
        
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (updated_matrix[i][j] == INT_MAX - 100) {
                    updated_matrix[i][j] = -1;
                } else{
                    return updated_matrix;
                }
            }
        }
        return updated_matrix;
    }
    
    bool can_travel_to(vector<vector<int>>& matrix, int r, int c) {
        return r >= 0 && r < matrix.size() && 
            c >= 0 && c < matrix[0].size() &&
            matrix[r][c] != 0;
    }
};
