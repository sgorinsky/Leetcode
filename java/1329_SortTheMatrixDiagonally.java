class Solution {
    public int[][] diagonalSort(int[][] mat) {
        for (int i = 0; i < mat.length; ++i)
            storeAndSortDiagonal(mat, i, 0);
        
        for (int j = 0; j < mat[0].length; ++j)
            storeAndSortDiagonal(mat, 0, j);
        
        return mat;
    }
    
    public void storeAndSortDiagonal(int[][] mat, int row, int col) {
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>((a, b) -> a - b);
        
        int i = row, j = col;
        while (i < mat.length && j < mat[0].length) 
            pq.add(mat[i++][j++]);
        
        while (!pq.isEmpty()) 
            mat[row++][col++] = pq.poll();
    }
}
