class Solution:
    def search(self, nums: List[int], target: int) -> int:
        first, last = 0, len(nums)-1
        while first<=last:
            midpoint = (first + last)>>1
            if nums[midpoint] == target:
                return midpoint
            elif target < nums[midpoint]:
                last = midpoint-1
            else:
                first = midpoint+1
        return -1
