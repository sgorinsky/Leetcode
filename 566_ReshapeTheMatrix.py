class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        if not nums or not nums[0]: return nums
        elif len(nums)*len(nums[0]) != r*c: return nums
        
        new_matrix = [[] for _ in range(r)]
        
        i, idx = 0, 0
        for row in nums:
            for entry in row:
                new_matrix[i].append(entry)
                if idx+1 == c:
                    i += 1
                    idx = 0
                else: idx += 1
        return new_matrix
