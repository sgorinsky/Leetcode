class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        jewels_set = set()
        for j in J:
            jewels_set.add(j)
            
        count = 0
        for s in S:
            if s in jewels_set:
                count += 1
        return count
