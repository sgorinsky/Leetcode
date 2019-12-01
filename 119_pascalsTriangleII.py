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
