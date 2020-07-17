# solution has a dragging pointer that makes sure no entries before it are negative
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum, current_sum, prior_stack_sum = -2147483648, 0, 0
        for i in range(len(nums)):
            prior_stack_sum, current_sum = current_sum, current_sum + nums[i]
            if current_sum > max_sum:
                max_sum = current_sum
            if prior_stack_sum < 0:
                current_sum = nums[i]
                if current_sum > max_sum:
                    max_sum = current_sum
        return max_sum

# inefficient solution: here to show how to improve it
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
