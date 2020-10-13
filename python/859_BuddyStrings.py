from collections import Counter
class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        if len(A) != len(B): return False
        
        count = 0
        for i, l in enumerate(A):
            if l != B[i]: count += 1
        
        A_counts, B_counts = Counter(A), Counter(B)
        if count == 2: return A_counts == B_counts
        elif count == 0:
            for k, v in A_counts.items():
                if v >= 2: return True
        return False
