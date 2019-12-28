class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        while i < len(nums):
            if i >= 2 and nums[i] == nums[i-1] == nums[i-2]:
                del nums[i]
                i -= 1
            i += 1
        return len(nums)
