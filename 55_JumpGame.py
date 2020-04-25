# Leetcode Day 26
# current_idx = i is cleaner
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        current_idx = len(nums)-1
        for i in range(len(nums)-2, -1, -1):
            if nums[i] >= current_idx-i:
                current_idx = i
        return current_idx == 0

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        length = len(nums)
        last_idx = length-1
        for i in range(length-2, -1, -1):
            if nums[i] >= last_idx-i:
                last_idx -= (last_idx-i)
        return last_idx == 0
