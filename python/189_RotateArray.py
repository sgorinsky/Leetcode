class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if nums:
            length = len(nums)
            nums[:] = nums[-k%length:] + nums[:-k%length]
