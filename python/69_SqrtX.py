class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 1: return 1
        left, right = 1, x // 2
        while left <= right:
            mid = left + (right - left) // 2
            sq = mid * mid
            if sq == x: return mid
            elif sq > x: right = mid - 1
            else: left = mid + 1
        return right

class Solution:
    def mySqrt(self, x: int) -> int:
        return int(x**.5)
