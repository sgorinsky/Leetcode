class Solution:
    cache = {}
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        if not triangle or not triangle[0]: return 0
        
        self.cache = {(0,0): triangle[0][0]}
        def helper(row, col):
            if row < 0 or col < 0 or row < col:
                return float('inf')
            elif (row, col) in self.cache:
                return self.cache[(row, col)]
            else:
                right = triangle[row][col] + helper(row-1, col)
                left = triangle[row][col] + helper(row-1, col-1)
                self.cache[(row, col)] = right if right < left else left
                return self.cache[(row, col)]

        high = float('inf')
        for i in range(len(triangle[len(triangle)-1])):
            current = helper(len(triangle)-1, i)
            if current < high:
                high = current
        return high
