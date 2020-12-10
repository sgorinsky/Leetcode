class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        if len(arr) < 3 or arr[0] > arr[1]: return False
        increasing = True
        for i in range(0, len(arr) - 1):
            if arr[i] == arr[i + 1]: return False
            if increasing: 
                if arr[i] > arr[i + 1]: increasing = False
            else: 
                if arr[i] < arr[i + 1]: return False
        return not increasing
