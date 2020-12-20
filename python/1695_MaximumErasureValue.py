class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        high = l = curr = 0
        lasts, counts = {}, {}
        for i, n in enumerate(nums):
            curr += n
            if n in counts and counts[n] > 0:
                for j in range(l, lasts[n] + 1):
                    curr -= nums[j]
                    counts[nums[j]] -= 1
                l = lasts[n] + 1

            counts[n] = 1
            lasts[n] = i
            high = max(curr, high)
        return high
