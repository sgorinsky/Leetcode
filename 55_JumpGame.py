class Solution:
    def canJump(self, nums: List[int]) -> bool:
        length = len(nums)
        last_idx = length-1
        for i in range(length-2, -1, -1):
            if nums[i] >= last_idx-i:
                last_idx -= (last_idx-i)
        return last_idx == 0
