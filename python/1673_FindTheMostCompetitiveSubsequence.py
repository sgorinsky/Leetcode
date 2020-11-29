class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        stack = []
        N = len(nums)
        
        for i, n in enumerate(nums):
            while stack and n < stack[-1] and N - i + len(stack) > k: stack.pop()
            stack.append(n)
        
        while len(stack) > k: stack.pop()
        return stack
