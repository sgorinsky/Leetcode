class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        dp = [0 for _ in range(2001)]
        dp[nums[0] + 1000] = 1
        dp[-nums[0] + 1000] += 1
        
        for i in range(1, len(nums)):
            next_dp = [0 for _ in range(2001)]
            for curr_sum in range(-1000, 1001, 1):
                if dp[curr_sum + 1000] > 0:
                    next_dp [curr_sum + nums[i] + 1000] += dp[curr_sum + 1000]
                    next_dp [curr_sum - nums[i] + 1000] += dp[curr_sum + 1000]
            dp = next_dp
        
        return 0 if S > 1000 else dp[S + 1000]
