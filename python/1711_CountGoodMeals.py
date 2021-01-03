class Solution:
    def countPairs(self, deliciousness: List[int]) -> int:
        high = 1000000007
        counts = defaultdict(int)
        pairs = 0
        for n in deliciousness:
            for i in range(22):
                pairs = (pairs + counts[(1 << i) - n]) % high
            counts[n] += 1
        return pairs
