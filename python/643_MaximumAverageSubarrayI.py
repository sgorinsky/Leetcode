class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        total = trail = 0
        high = -10001
        
        for i, n in enumerate(nums):
            if i < k:
                total += n
            else:
                high = max(high, total / k)
                total = total + n - nums[trail]
                trail += 1
        
        return max(high, total / k)
