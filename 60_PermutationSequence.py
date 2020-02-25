import functools
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        nums, s = [str(i) for i in range(1,n+1)], ''
        while nums:
            fact, idx = self.factorial(len(nums)-1), 0
            while k > fact:
                idx += 1
                k -= fact
            s += nums.pop(idx)
        return s
    
    def factorial(self, n: int) -> int:
        if n <= 1:
            return 1
        return functools.reduce(lambda x,y: x*y, range(1, n+1))
        
