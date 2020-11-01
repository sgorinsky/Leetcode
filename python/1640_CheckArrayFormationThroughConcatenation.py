class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        pieces.sort()
        i = 0
        while i < len(arr):
            left, right = 0, len(pieces) - 1
            mid = (left + right) >> 1
            while left <= right:
                if pieces[mid][0] == arr[i]: break
                elif pieces[mid][0] > arr[i]: right = mid - 1
                else: left = mid + 1
                mid = (left + right) >> 1
            for j in range(len(pieces[mid])):
                if arr[i] != pieces[mid][j]: return False
                i += 1
        return True
