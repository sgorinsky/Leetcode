class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        cands, counts = set(), set()
        for n in nums:
            if n not in counts:
                cands.add(n)
                counts.add(n)
            else:
                if n in cands:
                    cands.remove(n)
        
        for n in cands:
            return n
               
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

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        past_nums, start = {}, 0
        for n in nums:
            if n not in past_nums:
                past_nums[n] = 1
                start ^= n
            elif past_nums[n] == 1:
                start ^= n
                past_nums[n] += 1
        return start
