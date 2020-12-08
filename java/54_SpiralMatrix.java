class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> spiralElements = new ArrayList<Integer>();
        int i, j, layer;
        i = j = layer = 0;
        
        int m =  matrix.length, n = matrix[0].length;
        int rowSz = m - 1, colSz = n - 1;
        for (int x = 0; x < m * n; ++x) {
            if (matrix[i][j] == 101) {
                layer++; colSz--; rowSz--;
                i = j = layer;
            }
            
            spiralElements.add(matrix[i][j]);
            matrix[i][j] = 101;
            
            if (j < colSz && i == layer) j++;
            else if (i < rowSz && j == colSz) i++;
            else if (j > layer && i == rowSz) j--;
            else i--;
        }
        return spiralElements;
    }
}
