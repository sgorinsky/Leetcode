# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):
# binary search, one check per loop O(logN)
class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        left, right = 0, n
        while left <= right:
            mid = (left + right) >> 1
            curr = isBadVersion(mid)
            if curr:
                right = mid - 1
            else:
                left = mid + 1
        
        isBad = isBadVersion(left)
        return left+1 if not isBad else left

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
            elif not isBadVersion(mid-1):
                return mid
            else:
                right = mid-1
        return right
