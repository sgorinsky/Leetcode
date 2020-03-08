class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        end = len(nums)
        if end <= 1 : return 0
        for i in range(1, end-1):
            if nums[i-1] < nums[i] > nums[i+1]: return i
        return 0 if nums[0] > nums[1] else end-1
