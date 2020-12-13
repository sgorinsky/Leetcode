class Solution:
    def minPartitions(self, n: str) -> int:
        high = 1
        for d in n: high = max(int(d), high)
        return high
