class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if not nums: return []
        
        res = []
        low, high = nums[0], nums[0]
        for n in nums:
            if n > high + 1:
                res.append(f'{low}' if high == low else f'{low}->{high}')
                low, high = n, n
            else:
                high = n
        return res + [f'{low}' if high == low else f'{low}->{high}']
