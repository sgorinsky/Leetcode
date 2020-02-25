class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        length = len(nums)
        for i in range(length-2, -1, -1):
            if nums[i] < nums[i+1]:
                for j in range(i+1, length):
                    if nums[j] > nums[i] and j == length-1 or nums[j] >= nums[i] >= nums[j+1]:
                        nums[i], nums[j] = nums[j], nums[i]
                        nums[i+1:] = nums[:i:-1]
                        return nums
        nums[:] = nums[::-1]
        return nums
