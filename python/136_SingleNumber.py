class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        nums_set = set()
        for num in nums:
            if num not in nums_set:
                nums_set.add(num)
            else:
                nums_set.remove(num)
        for num in nums_set:
            return num

# better storage, simpler solution
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        xor_value = 0
        for num in nums:
            xor_value ^= num
        return xor_value
        
# one-liner
import functools
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return functools.reduce(lambda x,y: x ^ y, nums)        
