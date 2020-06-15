class Solution:
    digits = {}
    for i in range(10):
        digits[chr(ord('0')+i)] = i
    
    def addStrings(self, num1: str, num2: str) -> str:
        if not (num1 and num2):
            return num1 if not num2 else num2
        
        n1, curr_power = 0, 10**(len(num1)-1)
        for c in num1:
            n1 += self.digits[c] * curr_power
            curr_power //= 10
          
        n2, curr_power = 0, 10**(len(num2)-1)
        for c in num2:
            n2 += self.digits[c] * curr_power
            curr_power //= 10
            
        return str(n1+n2)
