# """
# This is ArrayReader's API interface.
# You should not implement it, or speculate about its implementation
# """
#class ArrayReader:
#    def get(self, index: int) -> int:

class Solution:
    def search(self, reader, target):
        """
        :type reader: ArrayReader
        :type target: int
        :rtype: int
        """
        left, right = 0, 10000
        while left <= right:
            mid = left + (right - left) // 2
            n = reader.get(mid)
            
            if n == target: return mid
            elif n < target: left = mid + 1
            else: right = mid - 1
            
        return -1
