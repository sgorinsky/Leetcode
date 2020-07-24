class Solution:
    def maxNumberOfApples(self, arr: List[int]) -> int:
        arr.sort()
        total, count, i = 5000, 0, 0
        while i < len(arr) and total > 0:
            if total - arr[i] >= 0:
                total -= arr[i]
                i += 1
                count += 1
            else:
                break
        return count
