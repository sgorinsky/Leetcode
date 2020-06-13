class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        colors = [0, 0, 0]
        for n in nums:
            if n == 0:
                colors[0] += 1
            elif n == 1:
                colors[1] += 1
            else:
                colors[2] += 1
        
        colors_idx = 0
        for i in range(len(nums)):
            while colors_idx < len(colors) and colors[colors_idx] == 0:
                colors_idx += 1
            nums[i] = colors_idx
            colors[colors_idx] -= 1
            
        return nums
        
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        reds, whites, blues = 0, 0, 0
        for n in nums:
            if n == 0:
                reds += 1
            elif n == 1:
                whites += 1
            elif n == 2:
                blues += 1
                
        nums[:reds], nums[reds:reds+whites], nums[reds+whites:reds+whites+blues] = [0] * reds, [1] * whites, [2] * blues
	return nums # not needed since problem only asks for in-place mutation

# iterated mutation instead of pythonic array mutation via array slicing
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        reds, whites, blues = 0, 0, 0
        for n in nums:
            if n == 0:
                reds += 1
            elif n == 1:
                whites += 1
            elif n == 2:
                blues += 1
                
        for i in range(reds): nums[i] = 0
        for i in range(reds, reds+whites): nums[i] = 1
        for i in range(reds+whites, reds+whites+blues): nums[i] = 2

