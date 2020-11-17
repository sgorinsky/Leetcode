class Solution:
    def longestMountain(self, A: List[int]) -> int:
        left = right = high = 0
        
        for i in range(1, len(A)):
            if A[i] > A[i-1]: continue
            elif A[i] == A[i-1]: left = i
            else:
                if i < len(A) - 1 and A[i] < A[i+1]:
                    high = max(high, i - left + 1)
                    left = i
                else:
                    right = i
            
            if i - 1 > left: high = max(high, right - left + 1)
            else: left = i
                
        return high if high > 2 else 0
