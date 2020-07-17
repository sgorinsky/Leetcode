class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        total = m
        if n > m*2:
            return 0
        if total > 0:
            for i in range(m+1, n+1):
                total &= i
                if not total:
                    break
        return total
