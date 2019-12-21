class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        total_set = []
        def helper(current_nums, current_set=[]):
            if not current_nums:
                total_set.append(current_set)
            
            for i in range(len(current_nums)):
                helper(current_nums[0:i]+current_nums[i+1:], 
                current_set+[current_nums[i]])
            
            return total_set
        helper(nums, [])
        return total_set
