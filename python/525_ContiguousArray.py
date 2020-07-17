# counts as keys, indices as values
class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        count = high = 0
        counts_dict = {0: -1}
        for i in range(len(nums)):
            count = count-1 if nums[i] == 0 else count+1
            
            if count in counts_dict: 
                high = max(high, i-counts_dict[count] )
            else: 
                counts_dict[count] = i

        return high
