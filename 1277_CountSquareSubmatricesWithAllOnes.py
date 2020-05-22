class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        if not matrix or not matrix[0]:
            return 0
        
        biggest_side = len(matrix) if len(matrix) < len(matrix[0]) else len(matrix[0])
        
        def checkSquare(side, row, col):
            if side+row >= len(matrix) or side+col >= len(matrix[0]):
                return False
            
            for i in range(row, side+row+1):
                for j in range(col, side+col+1):
                    if matrix[i][j] != 1:
                        return False
            return True
        
        def findSquares(side):
            total = 0
            for i in range(len(matrix)):
                if i + side >= len(matrix):
                    break
                for j in range(len(matrix[0])):
                    if j + side >= len(matrix[0]):
                        break
                    if checkSquare(side, i, j):
                        total += 1
            return total
        
        total_sides = 0
        idx = biggest_side-1
        while idx >= 0:
            total_sides += findSquares(idx)
            idx -= 1
        return total_sides
                        
