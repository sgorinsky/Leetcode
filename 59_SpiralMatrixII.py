class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        matrix = [[None]*n for _ in range(n)]
        row = col = count = 0
        size = n-1
        
        for num in range(1, n**2 + 1):
            if matrix[row][col]:
                row += 1
                col += 1
                count += 1
                size -= 1

            matrix[row][col] = num
            
            if row == count and col < size: col += 1
            elif row < size and col == size : row += 1
            elif row == size and col > count : col -= 1
            elif row > count and col == count: row -= 1
                
        return matrix
        
