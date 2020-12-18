class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        sums = {}
        for a in A:
            for b in B:
                sums[a + b] = sums[a + b] + 1 if a + b in sums else 1
        
        count = 0
        for c in C:
            for d in D:
                if -(c + d) in sums: count += sums[-(c + d)]
        return count
