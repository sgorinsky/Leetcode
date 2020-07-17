class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        curr_idx = 0
        for l in t:
            if curr_idx == len(s):
                return True
            if s[curr_idx] == l:
                curr_idx += 1
        return curr_idx == len(s)
