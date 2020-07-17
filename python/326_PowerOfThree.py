class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        three = 1
        while three < n: three *= 3
        return three == n
