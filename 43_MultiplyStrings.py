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
        '9':9,
        0:'0',
        1:'1',
        2:'2',
        3:'3',
        4:'4',
        5:'5',
        6:'6',
        7:'7',
        8:'8',
        9:'9'
    }
    def multiply(self, num1: str, num2: str) -> str:
        return self.intToStr(self.strToInt(num1) * self.strToInt(num2))
        
    def strToInt(self, s: str) -> int:
        num, idx, multiplier = 0, 0, 1
        while idx < len(s):
            num, idx, multiplier = num + self.digits[s[-1-idx]]*multiplier, idx+1, multiplier*10
        return num
    
    def intToStr(self, n: int) -> str:
        if n == 0:
            return '0'
        s = ''
        while n > 0:
            s, n = self.digits[n%10] + s, n//10
        return s
