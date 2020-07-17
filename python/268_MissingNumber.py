class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        num_set = set()
        high = 0
        
        for n in nums:
            if n > high: high = n
            num_set.add(n)
        
        for n in range(high+1):
            if n not in num_set:
                return n
        return high+1
