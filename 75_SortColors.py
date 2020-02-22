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
