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
