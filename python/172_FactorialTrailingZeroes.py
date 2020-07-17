class Solution:
    def trailingZeroes(self, n: int) -> int:
        zeroes = 0
        while n > 4 :
            zeroes += int(n//5)
            n = n / 5
        return zeroes
