from collections import Counter
class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        letter_counts = Counter(s)
        pos = 0
        
        for i, l in enumerate(s):
            if s[i] < s[pos]: pos = i
            
            letter_counts[l] -= 1
            if letter_counts[l] == 0: break
        
        return s[pos] + self.removeDuplicateLetters(s[pos:].replace(s[pos], '')) if s else ''
