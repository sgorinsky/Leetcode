class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum, max_array = -2147483648, []
        for i in range(len(nums)):
            current_sum = 0
            for j in range(i, len(nums)):
                current_sum += nums[j]
                if current_sum > max_sum:
                    max_sum = current_sum
        return max_sum
