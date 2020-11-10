class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix.size() == 0) return false;
        return search(matrix, 0, 0, matrix[0].size() - 1, matrix.size() - 1, target);
    }
    
    bool search(vector<vector<int>>& matrix, int left, int up, int right, int down, int target) {
        if (left > right || up > down || target < matrix[up][left] || target > matrix[down][right])
            return false;
        
        int mid = left + (right-left) / 2;
        int row = up;
        while (row <= down && matrix[row][mid] <= target) {
            if (matrix[row][mid] == target) 
                return true;
            row++;
        }
        return search(matrix, left, row, mid-1, down, target) || search(matrix, mid+1, up, right, row-1, target);
    }
};
