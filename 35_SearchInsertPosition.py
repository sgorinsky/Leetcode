class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums)-1
        while left < right:
            mid = (left+right) >> 1
            if mid < len(nums)-1 and nums[mid] < target < nums[mid+1]:
                return mid+1
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid -1
        
        return left + 1 if nums[left] < target else left

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
