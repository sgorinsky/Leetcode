class Solution:
    def trap(self, heights: List[int]) -> int:
        stack, length, current, total = [0], len(heights), 0, 0

        for height in heights:
            if stack and height >= stack[-1]:
                while stack and height >= stack[-1]:
                    current += (height - stack[-1])
                    del stack[-1]
                stack.append(height)
                total, current = total+current, 0
            else:
                stack.append(height)
        return total

class Solution:
    def trap(self, heights: List[int]) -> int:
        stack, length, current, total, last_current = [0], len(heights), 0, 0, 0
        i = 0
        while i < length:
            j = i + 1
            while j < length and i < j:
                if heights[j] >= heights[i]:
                    total += current
                    i = j
                else:
                    current = current + (heights[i] - heights[j])
                    j += 1
            current = 0
            i = j if i == j else i + 1
        return total
