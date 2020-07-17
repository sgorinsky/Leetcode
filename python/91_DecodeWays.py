class Solution:
    letter_values = {}
    for i in range(1, 27): letter_values[str(i)] = chr(64+i)
    
    cache = {'0':0, '':0}
    
    def numDecodings(self, s: str) -> int:
        if s in self.cache: return self.cache[s]
        
        return self.helper(s)
        
    def helper(self, s):
        if not s:
            return 1
        elif len(s) == 1:
            return 1 if s != '0' else 0
        else:
            if s in self.cache:
                return self.cache[s]
            else:
                if s[-2:] in self.letter_values:
                    self.cache[s] =  self.helper(s[:-1]) + self.helper(s[:-2]) if s[-1] != '0' else self.helper(s[:-2])
                else:
                    self.cache[s] = self.helper(s[:-1]) if s[-1] != '0' else 0
                return self.cache[s]
        
