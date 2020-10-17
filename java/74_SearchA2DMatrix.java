class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0 || matrix[0].length == 0) return false;
        
        int rows = matrix.length, cols = matrix[0].length;
        int left = 0, right = rows * cols - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int i = mid / cols, j = mid % cols;
            
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
}
