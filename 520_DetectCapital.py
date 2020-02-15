class Solution(object):
    def detectCapitalUse(self, word):
        return True if word.isupper() or word.islower() or word.istitle() else False
