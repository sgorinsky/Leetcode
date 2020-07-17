class Solution:
    signs = {'-', '+'}
    valid_digits = set()
    for i in range(10): valid_digits.add(chr(48+i))
        
    def myAtoi(self, string: str) -> int:
        
        s, num = string.strip(), ''
        
        if not s: return 0
        elif s[0] in self.valid_digits or s[0] in self.signs: 
            i = 0
            
            if s[0] in self.signs:
                if not len(s) < 2 and s[1] not in self.valid_digits: return 0
                elif len(s) == 1: return 0
                num, i = s[0], 1
                
            while i < len(s) and s[i] in self.valid_digits:
                num += s[i]
                i += 1
        else: return 0
        
        n = int(num) if num else 0
        
        if n <= -2147483648: return -2147483648
        elif n >= 2147483647: return 2147483647
        else: return n 
