class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        while len(stones) > 1:
            stones.sort()
            diff = stones[-1] - stones[-2]
            del stones[-1:-3:-1]
            if diff != 0: stones.append(diff)
        return stones[0] if stones else 0
