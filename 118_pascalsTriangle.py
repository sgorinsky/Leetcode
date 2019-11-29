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
                
        
