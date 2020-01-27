class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        DUMMY = -1000000
        i, j, row_length, col_length = 0, 0, len(matrix), len(matrix[0])
        while i < row_length:
            while j < col_length:
                if matrix[i][j] == 0:
                    for col in range(col_length):
                        matrix[i][col] = DUMMY if matrix[i][col] != 0 else 0
                    for row in range(row_length):
                        matrix[row][j] = DUMMY if matrix[row][j] != 0 else 0
                j += 1
            i += 1
            j = 0
        for r in range(row_length):
            for c in range(col_length):
                if matrix[r][c] == DUMMY:
                    matrix[r][c] = 0
