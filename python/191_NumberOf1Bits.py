class Solution:
    def hammingWeight(self, n: int) -> int:
        total = 0
        for i in range(32):
            total += (n & 1)
            n >>= 1 
        return total
