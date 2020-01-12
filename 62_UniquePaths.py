class Solution:
    cache = {(0,0): 1, (1,1): 1}
    def uniquePaths(self, x: int, y: int) -> int:
        if x <= 0 or y <= 0:
            self.cache[(x, y)] = 0
            return 0
        elif (x, y) in self.cache:
            return self.cache[(x, y)]
        elif (y, x) in self.cache:
            return self.cache[(y, x)]
        else:
            self.cache[(x, y)] = self.uniquePaths(x-1, y) + self.uniquePaths(x, y-1)
            return self.cache[(x, y)]
