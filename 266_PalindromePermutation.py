class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        letters = {}
        for l in s:
            letters[l] = 1 if l not in letters else letters[l]+1
        
        max_odds = 1 if len(s) % 2 == 1 else 0
        
        for k, v in letters.items():
            if v % 2 == 1:
                max_odds -= 1
            if max_odds < 0:
                return False
        
        return True
