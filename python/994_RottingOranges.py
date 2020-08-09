class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        time = -1
        hasFresh = True
        
        while hasFresh:
            hasFresh = False
            next_rotten = []
        
            for i, row in enumerate(grid):
                for j, orange in enumerate(row):
                    if orange == 2:
                        if i > 0 and grid[i-1][j] == 1:
                            next_rotten.append((i-1, j))
                        if j > 0 and grid[i][j-1] == 1:
                            next_rotten.append((i, j-1))
                        if i < len(grid)-1 and grid[i+1][j] == 1:
                            next_rotten.append((i+1, j))
                        if j < len(row)-1 and grid[i][j+1] == 1:
                            next_rotten.append((i, j+1))
                    elif orange == 1:
                        hasFresh = True
                        hasNothingAdjacent = True
                        if i > 0 and grid[i-1][j] != 0:
                            hasNothingAdjacent = False
                        if j > 0 and grid[i][j-1] != 0:
                            hasNothingAdjacent = False
                        if i < len(grid)-1 and grid[i+1][j] != 0:
                            hasNothingAdjacent = False
                        if j < len(row)-1 and grid[i][j+1] != 0:
                            hasNothingAdjacent = False
                        
                        if hasNothingAdjacent:
                            return -1
            
            if not next_rotten and hasFresh:
                return -1
            for x, y in next_rotten:
                grid[x][y] = 2
            time += 1
        return time
                
            
