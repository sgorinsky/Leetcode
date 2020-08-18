class Solution:
    def numsSameConsecDiff(self, N: int, K: int) -> List[int]:
        if N <= 1:
            res = [i for i in range(1, 10)]
            return [0] + res if N == 1 else res
        
        res = set()
        start = 10**(N-1)
        
        def findNextDigit(cand, d):
            if len(cand) == N:
                res.add(cand)
                return
            if d-K >= 0:
                findNextDigit(cand+str((d-K)), d-K)
            if d+K<10:
                findNextDigit(cand+str((d+K)), d+K)
            
        for i in range(1, 10):
            findNextDigit(str(i), i)
        
        return list(res)
