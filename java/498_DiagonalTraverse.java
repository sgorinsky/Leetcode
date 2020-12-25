class Solution {
    public int[] findDiagonalOrder(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) return new int[0]; 
        int r = matrix.length, c = matrix[0].length;
        int[] diagonals = new int[r * c];
        
        int i = 0, j = 0;
        boolean up = true;
        for (int idx = 0; idx < r * c; ++idx) {
            diagonals[idx] = matrix[i][j];
            if (up) {
                if (i == 0 || j == c - 1) {
                    if (j == c - 1)
                        i++;
                    else
                        j++;
                    up = false;
                } else {
                    i--;
                    j++;
                }
            } else {
                if (i == r - 1 || j == 0) {
                    if (i == r - 1)
                        j++;
                    else
                        i++;
                    up = true;
                } else {
                    i++;
                    j--;
                }
            }
        }
        return diagonals;
    }
}
