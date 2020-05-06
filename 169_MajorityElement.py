class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        counts = {}
        for n in nums:
            counts[n] = 1 if n not in counts else counts[n] + 1
            if counts[n] > len(nums)//2:
                return n
        return 0

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        num_dict, current_num, current_highest, half = {}, 0, 0, len(nums)//2
        
        for num in nums:
            num_dict[num] = 1 if num not in num_dict else num_dict[num]+1
            if num_dict[num] > current_highest:
                current_num, current_highest = num, num_dict[num]
            if current_highest > half:
                return current_num
        return current_num
