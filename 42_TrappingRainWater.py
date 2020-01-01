''' 
# Original approach: this may be more optimizable down the road

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
'''
class Solution:
    def trap(self, heights: List[int]) -> int:
        stack, length, current, total, last_current = [0], len(heights), 0, 0, 0
        i, k = 0, length-1
        while i < k:
            if heights[i] <= heights[k]:
                j = i + 1
                while i < j < length:
                    if heights[j] >= heights[i]:
                        total += current
                        i = j
                    else:
                        current += (heights[i] - heights[j])
                        j += 1
                current = 0
                i = i+1 if i != j else j
            else:
                j = k - 1
                while 0 <= j < k:
                    if heights[j] >= heights[k]:
                        total += current
                        k = j
                    else:
                        current += (heights[k] - heights[j])
                        j -= 1
                current = 0
                k = k-1 if k != j else j
        return total
