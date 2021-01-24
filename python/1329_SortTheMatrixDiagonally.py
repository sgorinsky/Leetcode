class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        def sort_diagonal(row, col):
            nonlocal n, m
            i, j = row, col
            diagonal = []
            while i < m and j < n:
                heappush(diagonal, mat[i][j])
                i += 1
                j += 1
            
            while diagonal:
                mat[row][col] = heappop(diagonal)
                row += 1
                col += 1
        
        m, n = len(mat), len(mat[0])
        for i in range(m):
            sort_diagonal(i, 0)
        
        for j in range(n):
            sort_diagonal(0, j)
            
        return mat
