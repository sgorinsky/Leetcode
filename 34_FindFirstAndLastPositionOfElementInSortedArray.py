# modified binary search to find first position of target and first position of target+1
#	only care when nums[mid] >= target b/c we approach first found target from rt	
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        first_pos = self.initialPos(nums, target)
        last_pos = self.initialPos(nums, target+1)-1
        
        return [first_pos, last_pos] if first_pos <= last_pos else [-1, -1]

        def initialPos(targ):
            first_pos = len(nums)
            left, right = 0, len(nums)-1
            while left <= right:
                mid = (left + right) >> 1
                if nums[mid] >= target:
                    first_pos = mid
                    right = mid - 1
                else:
                    left = mid + 1
            return first_pos
                
        
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
