class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix or not matrix[0]:
            return []
        
        r, c = len(matrix), len(matrix[0])
        i = j = 0
        diagonals = []
        up = True
        for _ in range(r * c):
            diagonals.append(matrix[i][j])
            if up:
                if i == 0 or j == c - 1:
                    if j == c - 1:
                        i += 1
                    else:
                        j += 1
                    up = False
                else:
                    i -= 1
                    j += 1
            else:
                if i == r - 1 or j == 0:
                    if i == r - 1:
                        j += 1
                    else:
                        i += 1
                    up = True
                else:
                    i += 1
                    j -= 1
        return diagonals
