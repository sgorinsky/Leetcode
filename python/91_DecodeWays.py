class Solution:
    def numDecodings(self, s: str) -> int:
        def helper(head):
            if head in cache: return cache[head]
            elif head == len(s): return 1
            elif head > len(s) or s[head] == '0': return 0
            
            cache[head] = helper(head + 1)
            if head + 2 <= len(s):
                n = int(s[head:head+2])
                if 1 <= n <= 26:
                    cache[head] += helper(head + 2)
            return cache[head]
        cache = {}
        return helper(0)

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
        
