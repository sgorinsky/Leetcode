class Solution:
    def peakIndexInMountainArray(self, A: List[int]) -> int:
        end = len(A)-1
        for i in range(1, end):
            if A[i-1] < A[i] > A[i+1]: return i
        return end
        
