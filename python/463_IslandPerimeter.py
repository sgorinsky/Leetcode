class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        perimeter = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    # row logic
                    if i > 0 and grid[i-1][j] == 0 or i == 0:
                        perimeter += 1
                    if i < len(grid)-1 and grid[i+1][j] == 0 or i == len(grid)-1:
                        perimeter += 1
                    
                    # col logic
                    if j > 0 and grid[i][j-1] == 0 or j == 0:
                        perimeter += 1
                    if j < len(grid[0])-1 and grid[i][j+1] == 0 or j == len(grid[0])-1:
                        perimeter += 1
        return perimeter

class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        
        def getUnitPerim(row, col):
            count = 0
            if grid[row][col] == 1:
                if row > 0 and grid[row-1][col] == 0 or row == 0: count += 1
                if row < len(grid)-1 and grid[row+1][col] == 0 or row == len(grid)-1: count += 1
                if col > 0 and grid[row][col-1] == 0 or col == 0: count += 1
                if col < len(grid[0])-1 and grid[row][col+1] == 0 or col == len(grid[0])-1: count += 1
            return count
        
        total = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                total += getUnitPerim(i, j)
        return total
