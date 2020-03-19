# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        left, right = 1, n
        while left < right:
            mid = (left + right)>>1
            
            if not isBadVersion(mid):
                left = mid+1
            else:
                if not isBadVersion(mid-1):
                    return mid
                else:
                    right = mid-1
        return right
