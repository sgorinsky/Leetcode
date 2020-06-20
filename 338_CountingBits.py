class Solution:
    def countBits(self, num: int) -> List[int]:
        return [bin(n)[2:].count('1') for n in range(num+1)]
