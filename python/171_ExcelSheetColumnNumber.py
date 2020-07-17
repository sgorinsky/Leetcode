class Solution:
    letters = {}
    for i in range(1, 27): letters[chr(64+i)] = i
        
    def titleToNumber(self, s: str) -> int:
        total, i, length = 0, 0, len(s)
        
        while i < length: 
            total += self.letters[s[i]]*(26**(length - (i+1)))
            i += 1
        return total
