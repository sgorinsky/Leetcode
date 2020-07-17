class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        nums_dict = {}
        
        for n in nums:
            nums_dict[n] = nums_dict[n] + 1 if n in nums_dict else 1
        
        length = len(nums)
        res = []
        for n, amt in nums_dict.items():
            if amt > length//3: res.append(n)
        return res
