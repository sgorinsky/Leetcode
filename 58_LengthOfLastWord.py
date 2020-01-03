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

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if not s:
            return 0
        
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
