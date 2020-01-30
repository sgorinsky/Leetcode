class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        past_nums, candidates = set(), set()
        for n in nums:
            if n not in past_nums:
                past_nums.add(n)
                candidates.add(n)
            else:
                if n in candidates:
                    candidates.remove(n)
        for n in candidates:
            return n
