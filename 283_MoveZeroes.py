class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        count, idx = 0, 0
        while idx < len(nums):
            if nums[idx] == 0:
                del nums[idx]
                count += 1
            else:
                idx += 1
        for i in range(count):
            nums.append(0)
        return nums
