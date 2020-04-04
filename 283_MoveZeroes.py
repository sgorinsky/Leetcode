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

# 30 day challenge solution
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i, count = 0, 0
        while i < len(nums):
            if nums[i] == 0:
                count += 1
                del nums[i]
            else:
                i += 1
        
        for i in range(count):
            nums.append(0)
