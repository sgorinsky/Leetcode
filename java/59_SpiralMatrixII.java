class Solution {
    public int[][] generateMatrix(int n) {
        int[][] matrix = new int[n][n];
        int i, j, layer;
        i = j = layer = 0;
        int sz = n - 1;
        
        for (int x = 1; x <= n * n; ++x) {
            if (matrix[i][j] != 0) {
                layer++; sz--;
                i = j = layer;
            }
            
            matrix[i][j] = x;
            
            if (j < sz && i == layer) j++;
            else if (i < sz && j == sz) i++;
            else if (j > layer && i == sz) j--;
            else i--;
        }
        return matrix;
    }
}
