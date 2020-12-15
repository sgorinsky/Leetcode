class Solution:
    # returns leftmost (or rightmost) index at which `target` should be inserted in sorted
    # array `nums` via binary search.
    def extreme_insertion_index(self, nums, target, left):
        lo = 0
        hi = len(nums)

        while lo < hi:
            mid = (lo + hi) // 2
            if nums[mid] > target or (left and target == nums[mid]):
                hi = mid
            else:
                lo = mid+1

        return lo


    def searchRange(self, nums, target):
        left_idx = self.extreme_insertion_index(nums, target, True)

        # assert that `left_idx` is within the array bounds and that `target`
        # is actually in `nums`.
        if left_idx == len(nums) or nums[left_idx] != target: return [-1, -1]
        return [left_idx, self.extreme_insertion_index(nums, target, False)-1]


# modified binary search to find first position of target and first position of target+1
#	only care when nums[mid] >= target b/c we approach first found target from rt	
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        first_pos = self.initialPos(nums, target)
        last_pos = self.initialPos(nums, target+1)-1
        
        return [first_pos, last_pos] if first_pos <= last_pos else [-1, -1]

    def initialPos(self, nums, target):
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
