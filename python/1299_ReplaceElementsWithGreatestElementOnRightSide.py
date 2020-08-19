class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        high = -1
        for i in range(len(arr)-1, -1, -1):
            arr[i], high = high, max(arr[i], high)
        return arr
