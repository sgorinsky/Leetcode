class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False
        top, bottom, row = 0, len(matrix)-1, None
        while top <= bottom:
            half = (top+bottom)>>1
            if matrix[half][0] > target:
                bottom = half-1
            elif matrix[half][len(matrix[0])-1] < target:
                top = half+1
            else:
                row = matrix[half]
                break
        
        if not row:
            return False
        
        left, right = 0, len(row)-1
        
        while left <= right:
            half = (left+right) >> 1
            if row[half] == target:
                return True
            elif row[half] > target:
                right = half-1
            else:
                left = half+1
        return False

# more efficient one-pass binary search
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or len(matrix[0]) == 0:
            return False
        row_length = len(matrix[0])
        left, right = 0, row_length*(len(matrix)-1) + row_length - 1
        while left <= right:
            half = (left + right) >> 1
            row, col = half//row_length, half%row_length
            if matrix[row][col] == target:
                return True
            elif matrix[row][col] > target:
                right = half - 1
            else:
                left = half + 1
        return False
