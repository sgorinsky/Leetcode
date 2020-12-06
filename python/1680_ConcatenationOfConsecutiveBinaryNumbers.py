class Solution:
    mod = 1000000007
    def concatenatedBinary(self, n: int) -> int:
        res = ""
        for x in range(1, n + 1):
            res += bin(x)[2:]
            new = int(res, 2)
            if new > self.mod:
                new %= self.mod
                res = bin(new)[2:]
        
        return int(res, 2)
