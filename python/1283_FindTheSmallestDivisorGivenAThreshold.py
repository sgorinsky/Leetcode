import functools
class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        computeSum = lambda x : functools.reduce(lambda a, b : a + ceil(b / x), nums, 0)
        
        left, right = 1, 2
        while computeSum(right) > threshold:
            left, right = right, right << 1
        
        while left <= right:
            pivot = (left + right) >> 1
            total = computeSum(pivot)
            
            if total > threshold: left = pivot + 1
            else: right = pivot - 1
                
        return left
