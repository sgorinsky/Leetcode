class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n <= 0:
            return False
        two = 1
        while n >= two:
            if two == n:
                return True
            two *= 2
        return False
