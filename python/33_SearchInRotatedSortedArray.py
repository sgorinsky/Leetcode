# much easier solution this time around
# idea for search builds from looking at portion of array that is sorted
#	and checking target based on sorted portion
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums: return -1
        left, right = 0, len(nums)-1
        
        while left < right:
            mid = (left+right) >> 1
            
            if nums[mid] == target: 
                return mid
            elif nums[mid] < nums[right]:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
            else:
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
    
        return left if nums[left] == target else -1

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
                
        
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        l, r = 0, n-1
        while l <= r:
            mid = l + (r - l)//2
            if nums[mid] == target: return mid
            if mid+1 < n and nums[mid+1] <= nums[r] : 
                if nums[mid + 1] <= target <= nums[r]:
                    l = mid + 1
                    continue
                else: 
                    r = mid - 1
                    continue
            if mid-1 >= 0 and nums[l] <= nums[mid-1] : 
                if nums[l] <= target <= nums[mid - 1]:
                    r = mid - 1
                    continue
                else: 
                    l = mid + 1
                    continue
            else: break
        return -1
        
