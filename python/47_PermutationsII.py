class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        total_set = []
        def helper(current_nums, current_set, count=0):
            if not current_nums:
                total_set.append(current_set)
            for i in range(len(current_nums)):
		if i == 0 or current_nums[i] != current_nums[i-1]:
                    helper(current_nums[0:i]+current_nums[i+1:],current_set+[current_nums[i]])
            return total_set
        return helper(nums, [], 0)
