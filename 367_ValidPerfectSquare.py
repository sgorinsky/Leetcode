# Leetcode May 9
# more concise than recursive binary solution
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        left, right = 0, num
        while left <= right:
            mid = (left+right)>>1
            sq_mid = mid**2
            if sq_mid == num:
                return True
            elif sq_mid > num:
                right = mid-1
            else:
                left = mid+1
        return False

class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        return self.binarySearch(num, 0, round(num/2+0.5))
    
    def binarySearch(self, num, left, right):
        if left > right:
            return False
        
        if left**2 == num or right**2 == num:
            return True
        
        combined = (left+right) // 2
        if combined ** 2 == num:
            return True
        elif num < combined ** 2:
            return self.binarySearch(num,left,combined-1)
        else:
            return self.binarySearch(num,combined+1,right)
