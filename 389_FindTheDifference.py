class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        letters_dict = {}
        for l in s:
            letters_dict[l] = 1 if l not in letters_dict else letters_dict[l] + 1
        
        for l in t:
            if l not in letters_dict or letters_dict[l] == 0:
                return l
            letters_dict[l] -= 1
