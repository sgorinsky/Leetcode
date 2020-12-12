class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        j = count = 1
        for i in range(1, len(nums)):
            count = count + 1 if nums[i] == nums[i-1] else 1
            if count < 3: 
                nums[j] = nums[i]
                j += 1
        return j

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        while i < len(nums):
            if i >= 2 and nums[i] == nums[i-1] == nums[i-2]:
                del nums[i]
                i -= 1
            i += 1
        return len(nums)
