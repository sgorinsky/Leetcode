class Solution:
    def countElements(self, arr: List[int]) -> int:
        nums_set = set()
        for n in arr:
            nums_set.add(n)
        count = 0
        for n in arr:
            if n+1 in nums_set: count += 1
        return count
