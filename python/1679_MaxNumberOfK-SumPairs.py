from collections import Counter
class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        counts = Counter(nums)
        count = 0
        for n in nums:
            complement = k - n
            if counts[complement] > 0:
                counts[complement] -= 1
                if counts[n] == 0:
                    continue
                counts[n] -= 1
                count += 1
        return count
