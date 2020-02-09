class Solution:
    def reverseBits(self, n: int) -> int:
        bits = 0
        for i in range(32):
            bits = bits << 1
            bits = bits | ( n & 1 )
            n = n >> 1
        return bits
