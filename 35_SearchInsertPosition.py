class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if len(nums) < 1:
            return 0
        i = 0
        while i < len(nums):
            if target <= nums[i]:
                return i
            i += 1
        return i
