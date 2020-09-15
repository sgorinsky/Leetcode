class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
        cache = {}
        def helper(idx, total):
            if idx in cache:
                return cache[idx]
            elif idx < 0:
                return total
            elif idx == 0:
                return total + nums[idx]
            
            cache[idx] = max(helper(idx-1, total), helper(idx-2, total) + nums[idx])
            return cache[idx]
        
        return helper(len(nums)-1, 0)

class Solution:
    def rob(self, nums: List[int]) -> int:
        prev = curr = 0
        for n in nums: prev, curr = curr, max(prev + n, curr)
        return curr
