class Solution:
    def maxSubarraySumCircular(self, A) -> int:
        step = 0
        all_negetive = 1
        for item in A:
            if item > 0:
                all_negetive = 0
                break
        if all_negetive:
            return max(A)
        dpmax,dpmin = [0] * len(A),[0] * len(A)
        dpmax[0] = A[0]
        dpmin[0] = A[0]
        while step <= len(A)-1:
            dpmax[step] = max(dpmax[step-1]+A[step],A[step])
            dpmin[step] = min(dpmin[step-1]+A[step],A[step])
            step += 1
        #print(dpmax)
        #print(dpmin)
        return max(max(dpmax),sum(A)-min(dpmin))
