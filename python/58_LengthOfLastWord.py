# original solution using str split
import re
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if not s:
            return 0
        split_string = re.split('\s+', s)
        if split_string[-1] == '':
            i = 0
            while split_string[-1-i] == '' and i < len(split_string)-1:
                i += 1
            return len(split_string[-1-i])
        else:
            return len(split_string[-1])

# no built-in methods
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        i, s = 0, ' ' + s
        
        while s[-1-i] == ' ' and i < len(s)-1:
            i += 1
            
        if i < len(s)-1:
            j = 0
            while s[-1-i-j] != ' ':
                j += 1
            return j
        else:
            return 0

# fast two-liner
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.strip().split(' ')
        return 0 if len(s) == 0 else len(s[-1])
