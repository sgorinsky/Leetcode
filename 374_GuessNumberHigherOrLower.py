# The guess API is already defined for you.
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        left, right = 1, n
        mid = (left+right)>>1
        
        res = guess(mid)
        
        while res != 0:
            mid = (left+right)>>1
            res = guess(mid)
            
            if res == 0: return mid
            elif res == -1: right = mid-1
            else: left = mid+1
        return mid