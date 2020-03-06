class Solution:
    def jump(self, nums: List[int]) -> int:
        if len(nums) <= 1: return 0
        idx, count, length = 0, 0, len(nums)-1
        
        while idx < length:
            furthest, next_idx = 0, 0
            if nums[idx]+idx < length:
                for i in range(1, nums[idx]+1):
                    if nums[idx+i] + i >= furthest:
                        furthest, next_idx = nums[idx+i]+i, idx+i
                count += 1
                idx = next_idx
            else: return count+1
        return countn
