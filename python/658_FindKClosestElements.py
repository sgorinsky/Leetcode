class Solution:
    def findClosestElements(self, nums: List[int], k: int, x: int) -> List[int]:
        left, right = 0, len(nums) - k
        while left < right:
            mid = left + (right - left) // 2
            if x - nums[mid] <= nums[mid + k] - x: right = mid
            else: left = mid + 1
        return nums[left:left+k]
