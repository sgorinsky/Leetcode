# DP solution -> obstacles indicate no acceptable path 
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if not (obstacleGrid and obstacleGrid[0]):
            return 1
        elif obstacleGrid[0][0] != 1:
            obstacleGrid[0][0] = 1
        else:
            return 0
        
        for i in range(len(obstacleGrid)):
            for j in range(len(obstacleGrid[0])):
                if obstacleGrid[i][j] == 1 and not i == j == 0:
                    obstacleGrid[i][j] = 0
                elif i > 0 and j > 0:
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1]
                elif i > 0:
                    obstacleGrid[i][j] = obstacleGrid[i-1][j]
                elif j > 0:
                    obstacleGrid[i][j] = obstacleGrid[i][j-1]
        return obstacleGrid[-1][-1]

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if not obstacleGrid:
            return 0
        elif  len(obstacleGrid[0]) == 0:
            return 1
        cache = {(0,0): int(obstacleGrid[0][0] == 0)}
        def helper(row, col):
            if obstacleGrid[row][col] == 1 or row < 0 or col < 0:
                cache[(row, col)] = 0
                return 0
            elif (row, col) in cache:
                return cache[(row, col)]
            else:
                cache[(row, col)] = helper(row-1, col) + helper(row, col-1)
                return cache[(row, col)]
        return helper(len(obstacleGrid)-1,len(obstacleGrid[0])-1)
