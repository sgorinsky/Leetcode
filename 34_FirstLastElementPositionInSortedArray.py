class Solution:
    def searchRange(self, nums_list: List[int], target_num: int) -> List[int]:
        def helper(nums, target, current_index):
            half = len(nums)//2
            if len(nums) < 1:
                return [-1, -1]
            elif nums[half] == target:
                start, idx = half, half
                while nums[idx] == target:
                    if idx == 0:
                        break
                    else:
                        start = idx
                    idx -= 1
                end, jdx = half, half
                while nums[jdx] == target:
                    if jdx == len(nums):
                        break
                    else:
                        end = jdx
                    jdx += 1
                return [start, end]
            elif nums[half] < target:
                return helper(nums[half:], target, current_index+half)
            else:
                return helper(nums[:half], target, current_index-half)
