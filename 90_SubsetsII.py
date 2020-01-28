class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        result = [[]]
        nums.sort()
        for n in nums:
            result += [[n]+entry for entry in result]
        
        check_result, i = set(), 1
        while i < len(result):
            tuple_entry = tuple(result[i])
            if tuple_entry not in check_result:
                check_result.add(tuple_entry)
                i += 1
            else:
                del result[i]
        return result
