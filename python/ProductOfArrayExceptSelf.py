class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        total, countZeroes = 1, 0
        for n in nums:
            if n == 0: 
                countZeroes += 1
                if countZeroes > 1: return [0] * len(nums)
            else: 
                total *= n

        for i in range(len(nums)):
            if nums[i] != 0: 
                if countZeroes: nums[i] = 0
                else: nums[i] = int(total * (nums[i]**-1))
            else: nums[i] = total

        return nums
