class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        nums_dict = {}
        
        for n in nums:
            nums_dict[n] = 1 if n not in nums_dict else nums_dict[n] + 1
            
        res, i = [0,0], 0
        for key, value in nums_dict.items():
            if value == 1: 
                res[i] = key
                i += 1
        
        return res
