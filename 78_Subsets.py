class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res, sets = [[]], set()
        def helper(arr):
            if not arr:
                return res
            
            if tuple(sorted(arr)) not in sets:
                sets.add(tuple(sorted(arr)))
                res.append(sorted(arr))
            else:
                return res
                
            for i in range(len(arr)):
                helper(arr[0:i] + arr[i+1:])
            
            return res
        
        return helper(nums)

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        output = [[]]
        
        for num in nums:
            output += [curr + [num] for curr in output]
        
        return output
