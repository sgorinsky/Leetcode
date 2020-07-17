from collections import Counter 
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        n = len(s)
        m = len(p)
        res = []
        
        if m > n or not s:
            return res
        
        p_count = Counter(p)
        curr_count = Counter(s[:m])
        if p_count == curr_count:
            res.append(0)
        
        for i, (out, add) in enumerate(zip(s, s[m:])):
            curr_count[out] -= 1
            curr_count[add] += 1
            if p_count == +curr_count: # + only checks positive numbers in hash
                res.append(i+1)
        return res
