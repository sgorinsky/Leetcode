class Solution:
    def searchRange(self, nums: List[int], target: int) -> int:
        if not nums:
            return [-1, -1]
        first, last = 0, len(nums)-1

        while first<=last:
            midpoint = (first + last)>>1
            if nums[midpoint] == target:
                while nums[first] != target:
                    first += 1
                while nums[last] != target:
                    last -= 1
                return [first, last]
            elif target < nums[midpoint]:
                last = midpoint-1
            else:
                first = midpoint+1
        return [-1,-1]
