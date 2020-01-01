class Solution:
    def trap(self, heights: List[int]) -> int:
        stack, length, current, total, last_current = [0], len(heights), 0, 0, 0
        i, k = 0, length-1
        while i < k:
            if heights[i] <= heights[k]:
                j = i + 1
                while i < j <= k:
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
                while i <= j < k:
                    if heights[j] >= heights[k]:
                        total += current
                        k = j
                    else:
                        current += (heights[k] - heights[j])
                        j -= 1
                current = 0
                k = k-1 if k != j else j
        return total
