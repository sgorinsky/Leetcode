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
