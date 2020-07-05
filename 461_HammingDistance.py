class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        x, y = bin(x)[2:], bin(y)[2:]
        
        if len(x) < len(y):
            x = '0'*(len(y)-len(x)) + x
        else:
            y = '0'*(len(x)-len(y)) + y
            
        count = 0
        for i in range(len(x)):
            count += int(x[i]) ^ int(y[i])
        return count
        
