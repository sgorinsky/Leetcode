class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        count = trail = 0
        curr_product = 1
        for i, n in enumerate(nums):
            curr_product *= n
            while curr_product >= k and trail <= i:
                curr_product //= nums[trail]
                trail += 1
            count += (i - trail + 1)
        return count
