class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        if t < 0: return False
        d = {}
        for i, (n, b)  in enumerate(zip(nums, map(lambda x: x // (t + 1), nums))):
            if b in d or min(n - d.get(b - 1, float('-inf')), d.get(b + 1, float('inf')) - n) <= t: return True
            d[b] = n
            if i >= k: del d[nums[i - k] // (t + 1)]
        return False
