class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        nums.sort()
        for i in range(1, len(nums)):
            if nums[i] == nums[i-1]: return nums[i]
        return -1

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        nums_set = set()
        for n in nums:
            if n in nums_set:
                return n
            else:
                nums_set.add(n)
        return -1

# Floyd's Tortoise and Hare algorithm for Cycle Detection
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        tortoise, hare = nums[0], nums[nums[0]]
        while tortoise != hare:
            tortoise, hare = nums[tortoise], nums[nums[hare]]
        
        tortoise = 0
        while tortoise != hare:
            tortoise, hare = nums[tortoise], nums[hare]
            
        return tortoise
