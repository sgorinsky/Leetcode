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
