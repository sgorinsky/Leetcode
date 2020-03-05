class Solution:
    def jump(self, nums: List[int]) -> int:
        idx, count, end = 0, 1, len(nums)
        while idx < end:
            high, jump_idx = 0, 0
            
            for i in range(1, nums[idx]+1):
                if idx+i+nums[idx+i] >= end: return count
                elif nums[idx+i] + (i-idx) >= high:
                    high = nums[idx+i] + (i-idx)
                    jump_idx = idx + i
            idx = jump_idx
            count += 1
        return count
