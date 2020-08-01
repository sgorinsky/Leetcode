class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        isUpper = True
        for i, l in enumerate(word):
            if i == 0:
                isUpper = l == l.upper()
            elif isUpper:
                if i == 1 and l == l.lower():
                    isUpper = False
                elif l != l.upper():
                    return False
            elif l != l.lower():
                return False
        return True

class Solution(object):
    def detectCapitalUse(self, word):
        return word.isupper() or word.islower() or word.istitle() 
