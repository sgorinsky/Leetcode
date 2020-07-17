class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return len(nums)
        idx = 1
        last = nums[0]
        while idx < len(nums):
            if last == nums[idx]:
                del nums[idx]
            else:
                last = nums[idx]
                idx += 1
            
        return len(nums)
