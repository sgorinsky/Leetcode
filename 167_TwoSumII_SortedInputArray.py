class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        nums_storage = {}
        
        for i, num in enumerate(numbers):
            if target-num in nums_storage:
                return [nums_storage[target-num], i+1]
            else:
                nums_storage[num] = i+1
        return [0, 0]
