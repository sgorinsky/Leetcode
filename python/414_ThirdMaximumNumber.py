class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        highs = set()
        for n in nums:
            highs.add(n)
            if len(highs) > 3:
                highs.remove(min(highs))
                
        return min(highs) if len(highs) == 3 else max(highs)
