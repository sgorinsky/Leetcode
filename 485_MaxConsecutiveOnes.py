class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        count, total = 0, 0
        for n in nums:
            if n == 1:
                count += 1
                if count > total:
                    total = count
            else: count = 0
        return total
