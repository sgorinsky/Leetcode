class Solution:
    def trap(self, heights: List[int]) -> int:
        stack, length, current, total = [0], len(heights), 0, 0

        for height in heights:
            if stack and height >= stack[-1]:
                while stack and height >= stack[-1]:
                    current += (height - stack[-1])
                    del stack[-1]
                stack.append(height)
                total, current, count = total+current, 0
            else:
                stack.append(height)
        return total
