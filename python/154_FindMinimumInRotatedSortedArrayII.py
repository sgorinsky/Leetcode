class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums)-1
        lowest = float('inf')
        while left <= right:
            mid = (left + right) >> 1
            lowest = min(lowest, nums[left], nums[right], nums[mid])
            if nums[right] > nums[mid] >= nums[left] or nums[right] >= nums[mid] > nums[left]:
                    return nums[left]
            else:
                if nums[left] >= nums[right]:
                    if mid > 0 and nums[mid] < nums[mid-1]:
                        return nums[mid]
                    elif mid < len(nums)-1 and nums[mid+1] < nums[mid]:
                        return nums[mid+1]
                    elif nums[mid] == nums[left] == nums[right]:
                        for i in range(left, mid):
                            if nums[i] != nums[mid]:
                                return min(lowest, nums[i])
                        left = mid + 1
                        
                    elif nums[mid] > nums[right]:
                        left = mid + 1
                    else:
                        right = mid - 1
                else:
                    return nums[left]
                
        return lowest
