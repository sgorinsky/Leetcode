class Solution:
    def reverseString(self, s: List[str]) -> None:
        index = 0
        while index < len(s)//2 and len(s) > 1:
            s[index], s[-1-index] = s[-1-index], s[index]
            index += 1
        return s

#this doesn't work unless you increase recursion depth, but can't on Leetcode
import sys
sys.setrecursionlimit(1500)
class Solution:
    left = 0
    right = -1
    
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        if self.left >= len(s) + self.right or len(s) <= 1:
            return ''
        
        hold = s[self.left]
        s[self.left] = s[self.right]
        s[self.right] = hold
        self.right -= 1
        self.left += 1
        
        self.reverseString(s)
