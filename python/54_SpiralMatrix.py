class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []
        
        row = col = count = 0
        row_size, col_size, size = len(matrix)-1, len(matrix[0])-1, len(matrix)*len(matrix[0])
        spiral_output = []
        
        for i in range(size):
            if row == col == count and i != 0:
                row = col = count = count + 1
                row_size -= 1
                col_size -= 1

            spiral_output.append(matrix[row][col])
            
            if row == count and col < col_size: col += 1
            elif row < row_size and col == col_size: row += 1
            elif row == row_size and col > count: col -= 1
            elif row > count and col == count: row -= 1
        
        return spiral_output
