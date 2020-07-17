class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        self.checked_grid = [[False for i in range(len(grid[0]))] for i in range(len(grid))]
        self.islands = 0
        def check_surrounding(row, col):
            if row < 0 or col < 0 or row >= len(grid) or col >= len(grid[0]) or self.checked_grid[row][col]:
                return False
            else:
                self.checked_grid[row][col] = True
                if grid[row][col] == '0':
                    return False
                else:
                    for i in [-1, 1]:
                        check_surrounding(row+i, col)
                        check_surrounding(row, col+i)
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if not self.checked_grid[i][j]:
                    if grid[i][j] == '1':
                        self.islands += 1
                    check_surrounding(i, j)
        
        return self.islands
