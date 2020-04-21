# """
# This is BinaryMatrix's API interface.
# You should not implement it, or speculate about its implementation
# """
#class BinaryMatrix(object):
#    def get(self, x: int, y: int) -> int:
#    def dimensions(self) -> list[]:

class Solution:
    def leftMostColumnWithOne(self, binaryMatrix: 'BinaryMatrix') -> int:
        [rows, cols] = binaryMatrix.dimensions()
        
        i, j = 0, cols-1
        last_one_col = -1
        
        while i < rows and j >= 0:
            pointer = binaryMatrix.get(i, j)
            if pointer:
                last_one_col = j
                j -= 1
            else:
                i += 1
            
        return last_one_col
