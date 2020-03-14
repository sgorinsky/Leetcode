class Solution:
    numbers = {0: 'Z'}
    for i in range(1, 27): numbers[i] = chr(64+i)
    
    def convertToTitle(self, n: int) -> str:
        s = ''
        while n > 0:
            s = self.numbers[n%26] + s
            if not n % 26: n = (n//26)-1
            else: n //= 26
        return s

# less checks
class Solution:
    numbers = {0: 'Z'}
    for i in range(1, 27): numbers[i] = chr(64+i)
    
    def convertToTitle(self, n: int) -> str:
        s = ''
        while n > 0:
            s = self.numbers[n%26] + s
            if n % 26: n //= 26
            else: n = n//26 - 1
        return s
