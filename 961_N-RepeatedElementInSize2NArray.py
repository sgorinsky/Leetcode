class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        nums = {}
        for n in A:
            nums[n] = nums[n]+1 if n in nums else 1
            if nums[n] == len(A)//2:
                return n
        return -1
