class Solution:
    def canWinNim(self, n: int) -> bool:
        if n < 4:
            return True
        else:
            return n & 1 or n//2 & 1
