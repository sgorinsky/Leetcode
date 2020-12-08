class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        modded = [0 for _ in range(60)]
        count = 0
        
        for t in time: modded[t % 60] += 1
        for t in range(0, 31):
            if t == 0 or t == 30:
                for x in range(1, modded[t]):
                    count += x
            else:
                count += (modded[t] * modded[60 - t])
        
        return count
