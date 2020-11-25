class Solution:
    def smallestRepunitDivByK(self, K: int) -> int:
        if K % 2 == 0 or K % 5 == 0: return -1
        n = length = 1
        
        while n < 10000000:
            if n % K == 0 or n == 0: return length
            n = (n * 10 + 1) % K
            length += 1
        
        return -1
