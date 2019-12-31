class Solution:
    def trap(self, heights: List[int]) -> int:
        stack, length, current, total = [0], len(heights), 0, 0
        
        for height in heights:
            if height >= stack[-1]:
                j = 0
                while height >= stack[-1-j]:
                    current
