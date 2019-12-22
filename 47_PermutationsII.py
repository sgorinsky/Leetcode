class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        total_set = []
        past_sets = set()
        def helper(current_nums, current_set, count=0):
            if not current_nums:
                tuplified_current_set = tuple(current_set)
                if tuplified_current_set not in past_sets:
                    total_set.append(current_set)
                    past_sets.add(tuplified_current_set)
            for i in range(len(current_nums)):
                helper(current_nums[0:i]+current_nums[i+1:],current_set+[current_nums[i]], count+1)
            return total_set
        return helper(nums, [], 0)
