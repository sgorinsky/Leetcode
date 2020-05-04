class Solution:
    def findComplement(self, num: int) -> int:
        bin_string = bin(num)[2:]
        res = ''
        for l in bin_string:
            res += '0' if l == '1' else '1'
        return int(res, 2)
