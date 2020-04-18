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


# iterative solution that doesn't compare top and left when row or col is 0
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if len(grid) <= 0 or grid is None:
            return 0
        rows = len(grid)
        cols = len(grid[0])
        
        for i in range(rows):
            for j in range(cols):
                if r==c==0: # We just want to skip the top-left corner of the grid
                    continue
                if r-1<0: # Cases for elements in top row
                    grid[r][c] = grid[r][c] + grid[r][c-1]  
                elif c-1<0: # Cases for elements in leftmost column
                    grid[r][c] = grid[r][c] + grid[r-1][c]  
                else: # Normal cell
                    grid[r][c] = grid[r][c] + min(grid[r-1][c], grid[r][c-1])               
        return grid[rows-1][cols-1] # We have got the minimum path accumaled at the bottom-right corner, just return this
