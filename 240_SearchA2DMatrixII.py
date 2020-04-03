class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        def helper_search(row):
            left, right = 0, len(row)-1
            while left < right:
                half = (left + right) >> 1
                if row[half] == target:
                    return True
                elif row[half] > target:
                    right = half-1
                else:
                    left = half + 1
            return row[left] == target if row else False
        
        for row in matrix:
            exists = helper_search(row)
            if exists: return True
        return False
