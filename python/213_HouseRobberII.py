class Solution:
    def rob(self, nums: List[int]) -> int:
        N = len(nums)
        if N == 1: return nums[0]
        
        def rob_path(start, end):
            prev = curr = 0
            for i in range(start, end): prev, curr = curr, max(prev + nums[i], curr)
            return curr
        
        return max(rob_path(0, N-1), rob_path(1, N))
