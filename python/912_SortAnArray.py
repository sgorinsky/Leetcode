class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def split(start, end):
            if start == end: return [nums[start]]
            
            first, second = split(start, (start + end) // 2), split((start + end) // 2 + 1, end)
            return merge(first, second)
        
        def merge(a, b):
            merged_array = []
            left = right = 0
            
            while left < len(a) or right < len(b):
                if right >= len(b) or (left < len(a) and a[left] < b[right]):
                    merged_array.append(a[left])
                    left += 1
                else:
                    merged_array.append(b[right])
                    right += 1
            return merged_array
        
        return split(0, len(nums) - 1)
            
            
