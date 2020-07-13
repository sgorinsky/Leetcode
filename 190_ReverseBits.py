class Solution:
    def reverseBits(self, n: int) -> int:
        bin_n = bin(n)[2:]
        bin_n = '0'*(32-len(bin_n)) + bin_n
        return int('0b' + bin_n[::-1], 2)

class Solution:
    def reverseBits(self, n: int) -> int:
        bits = 0
        for i in range(32):
            bits = bits << 1
            bits = bits | ( n & 1 )
            n = n >> 1
        return bits
