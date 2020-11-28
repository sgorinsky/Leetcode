class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        def dfs(idx, curr_target):
            if curr_target in memo:
                return memo[curr_target]
            elif curr_target == 0:
                return True
            elif idx == 0 or curr_target < 0:
                return False
            
            memo[curr_target] = dfs(idx - 1, curr_target - nums[idx]) or dfs(idx - 1, curr_target)
            return memo[curr_target]
            
        memo = {}
        total = sum(nums)
        return total % 2 == 0 and dfs(len(nums) - 1, total // 2)
        
