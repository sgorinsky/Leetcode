import re
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = re.sub('[\W_]+', '', s).lower()
        half = [len(s)//2, len(s)//2] if len(s)&1 else [len(s)//2, len(s)//2-1]
        return s[:half[0]] == s[-1:half[1]:-1] if s else True
        
