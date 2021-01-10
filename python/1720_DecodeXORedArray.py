class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        res = [first]
        for n in encoded:
            res.append(n ^ res[-1])
        return res
