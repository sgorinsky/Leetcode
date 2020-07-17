# In order to find all possible combinations that equal target, memoized backtracking solution
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        self.cache = {}
        
        def helper(arr, curr):
            if curr > target:
                return 0
            elif curr == target:
                return 1
            elif curr in self.cache:
                return self.cache[curr]
            
            total = 0
            for i in range(len(arr)):
                if curr+arr[i] not in self.cache:
                    self.cache[curr+arr[i]] = helper(arr, curr+arr[i])
                total += self.cache[curr+arr[i]]
            
            return total
        
        return helper(nums, 0)
