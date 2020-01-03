class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums:
            return -1
        elif len(nums) == 1:
            return (nums[0] == target) - 1
        
        midpoint = (len(nums)-1) >>1
        first, last, pivot = 0, len(nums)-1, midpoint
        # find pivot
        while not (nums[midpoint] < nums[midpoint-1]):
            midpoint = (last + first) >> 1
            if nums[first] > nums[midpoint]:
                last = midpoint - 1
            elif nums[last] < nums[midpoint]:
                first = midpoint + 1
            else:
                if nums[midpoint] > nums[first]:
                    midpoint = first
                else:
                    last = midpoint - 1
            pivot = midpoint
        without_pivot = self.binary_search(nums[pivot:]+nums[:pivot], target)
        return (pivot + without_pivot) % len(nums) if without_pivot != -1 else -1
        
    # binary search 
    def binary_search(self, nums: List[int], target: int) -> int:
        first, last = 0, len(nums) - 1
        while first <= last:
            midpoint = (first + last) >> 1
            if nums[midpoint] == target:
                return midpoint
            elif nums[midpoint] > target:
                last = midpoint - 1
            else:
                first = midpoint + 1
        return -1
                
        