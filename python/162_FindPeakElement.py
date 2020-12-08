class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        def search(left, right):
            if left == right: return left
            mid = left + (right - left) // 2
            return search(left, mid) if nums[mid] > nums[mid + 1] else search(mid + 1, right)

        return search(0, len(nums) - 1)

class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        end = len(nums)
        if end <= 1 : return 0
        for i in range(1, end-1):
            if nums[i-1] < nums[i] > nums[i+1]: return i
        return 0 if nums[0] > nums[1] else end-1
