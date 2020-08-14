from random import randint
class Solution:

    def __init__(self, nums: List[int]):
        self.num_indices = {}
        for i, n in enumerate(nums):
            if n not in self.num_indices:
                self.num_indices[n] = [i]
            else:
                self.num_indices[n].append(i)

    def pick(self, target: int) -> int:
        return self.num_indices[target][randint(0, len(self.num_indices[target])-1)]


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)
