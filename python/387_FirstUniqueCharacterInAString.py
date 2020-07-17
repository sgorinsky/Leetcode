class Solution:
    def firstUniqChar(self, s: str) -> int:
        letter_counts = {}
        for l in s:
            letter_counts[l] = 1 if l not in letter_counts else letter_counts[l] + 1
            
        for i in range(len(s)):
            if letter_counts[s[i]] == 1:
                return i
        return -1
