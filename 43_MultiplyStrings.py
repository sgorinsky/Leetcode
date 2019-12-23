class Solution:
    digits = {
        '0':0,
        '1':1,
        '2':2,
        '3':3,
        '4':4,
        '5':5,
        '6':6,
        '7':7,
        '8':8,
        '9':9
    }
    def multiply(self, num1: str, num2: str) -> str:
        return str(self.convertStrToNum(num1) * self.convertStrToNum(num2))
        
    def convertStrToNum(self, s: str) -> int:
        num, idx, multiplier = 0, 0, 1
        while idx < len(s):
            num, idx, multiplier = num + self.digits[s[-1-idx]]*multiplier, idx+1, multiplier*10
        return num
