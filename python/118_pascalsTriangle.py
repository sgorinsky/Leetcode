class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        triangle = [[1]]
        if numRows == 0:
            return []
        elif numRows == 1:
            return triangle
        def pascalsTriangle(totalRows, currRow):
            
            if currRow+1 == totalRows:
                triangle.append([1 if i == 0 or i == currRow else triangle[currRow-1][i-1] + triangle[currRow-1][i] for i in range(currRow+1)])
            else:
                triangle.append([1 if i == 0 or i == currRow else triangle[currRow-1][i-1] + triangle[currRow-1][i] for i in range(currRow+1)])
                pascalsTriangle(totalRows, currRow+1)
            return triangle
        return pascalsTriangle(numRows, 1)
                
class AnotherSolution:
    memo = {(0,0): 1, (1,0): 1, (1,1):1}
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows <= 0:
            return []
        def getEntry(row, column):
            if (row, column) in self.memo:
                return self.memo[(row, column)]
            elif column == 0 or column == row:
                return 1
            else:
                self.memo[(row, column)] = getEntry(row-1, column) + getEntry(row-1, column-1)
                return self.memo[(row, column)]
        
        triangle = []
        row = 0
        while numRows != row:
            triangle.append([getEntry(row, col) for col in range(row+1)])
            row += 1
        return triangle        
