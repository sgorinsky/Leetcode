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
