class Solution:
    cache, lowest = {}, float('inf')
    def minPathSum(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]: return 0
        
        def helper(row, col, total):
            if row == 0 == col:
                if total+grid[0][0] < self.lowest:
                    self.lowest = total+grid[0][0]
                return self.lowest
            else:
                if 0 < row < len(grid): helper(row-1, col, total+grid[row][col])
                if 0 < col < len(grid[0]): helper(row, col-1, total+grid[row][col])
                
                return self.lowest
        return helper(len(grid)-1, len(grid[0])-1, 0)
