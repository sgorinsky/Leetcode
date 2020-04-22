# This O(N^2) time and O(1) space solution exceeds time limit but works
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = 0
        for i in range(len(nums)):
            curr = 0
            for j in range(i, len(nums)):
                curr += nums[j]
                if curr == k:
                    count += 1
        return count
