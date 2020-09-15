class Solution:
    def rob(self, nums: List[int]) -> int:
        prev = curr = 0
        for n in nums: prev, curr = curr, max(prev + n, curr)
        return curr
