class Solution:
    cache = {(0, 0): 1, (1,0): 1}
    def getRow(self, rowIndex: int) -> List[int]:
        def helper(i, j):
            if (i, j) in self.cache:
                return self.cache[(i, j)]
            elif (i, i-j) in self.cache:
                return self.cache[(i, i-j)]
            else:
                if j == i or j == 0:
                    self.cache[(i, j)] = 1
                    return self.cache[(i, j)]
                self.cache[(i, j)] = helper(i-1, j-1) + helper(i-1, j)
                return self.cache[(i, j)]
        
        return [helper(rowIndex, col) for col in range(rowIndex+1)]

# more recent solution is more concise
class Solution:
    cache = {(0,0): 1, (1,0): 1, (1,1):1}
    def getRow(self, rowIndex: int) -> List[int]:
        def helper(row, col):
            if (row, col) in self.cache: 
                return self.cache[(row, col)]
            else:
                if col == 0 or col == row:
                    self.cache[(row, col)] = 1
                    return 1
                else:
                    self.cache[(row, col)] = helper(row-1, col) + helper(row-1, col-1)
                    return self.cache[(row, col)]
        res = []
        for i in range(rowIndex+1):
            res.append(helper(rowIndex, i))
        return res

# less recent solution
class Solution:
    memo = {(0,0): 1, (1,0): 1, (1,1):1}
    def getRow(self, rowIndex: int) -> List[int]:
        if rowIndex <= 0:
            return [1]
        def getEntry(row, column):
            if (row, column) in self.memo:
                return self.memo[(row, column)]
            # checking for symmetric row entry
            elif (row, row-column) in self.memo:
                return self.memo[(row, row-column)]
            elif column == 0 or column == row:
                return 1
            else:
                self.memo[(row, column)] = getEntry(row-1, column) + getEntry(row-1, column-1)
                # additional storage helps optimize for bigger triangles 
                self.memo[(row, row-column)] = self.memo[(row, column)]
                return self.memo[(row, column)]
        return [getEntry(rowIndex, col) for col in range(rowIndex+1)]
