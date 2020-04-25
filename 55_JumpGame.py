# Leetcode Day 26
# forward-pass, slightly messier than backwards traversal
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        last = nums[0]
        for i in range(len(nums)):
            if nums[i] == 0 and last < i: # if can't get past 0, can't jump
                return False
            elif nums[i] + i > last and last >= i: # if we can get to nums[i]+i and it's greater than the current furthest point we can get to, that's the new furthest point
                last = nums[i] + i

        return last >= len(nums)-1

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
