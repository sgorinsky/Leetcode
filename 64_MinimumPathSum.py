class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]:
            return 0
        
        self.cache = {(0,0): grid[0][0]}
        def helper(row, col):
            if (row, col) in self.cache:
                return self.cache[(row, col)]
            else:
                left = grid[row][col] + helper(row-1, col) if row >= 0 else float('inf')
                right = grid[row][col] + helper(row, col-1) if col >= 0 else float('inf')
                
                self.cache[(row, col)] = min(left, right)
                return self.cache[(row, col)]
    
        return helper(len(grid)-1, len(grid[0])-1)


# dynamic programming solution that mutates entries in array while iterating through grid
# we know that the we just have to find the min of entries above and to the left when row > 0 and col > 0
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if row == col == 0:
                    continue
                elif row == 0:
                    grid[row][col] = grid[row][col] + grid[row][col-1]
                elif col == 0:
                    grid[row][col] = grid[row][col] + grid[row-1][col]
                else:
                    grid[row][col] = grid[row][col] + min(grid[row-1][col], grid[row][col-1])
            
        return grid[len(grid)-1][len(grid[0])-1] if grid and grid[0] else 0
