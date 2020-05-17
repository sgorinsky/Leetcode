class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        length = len(num)
        if length <= k:
            return '0'
        
        res = []
        for i in range(length):
            curr = int(num[i])
            while res and k and res[-1] > curr:
                k -= 1
                res.pop()
            res.append(curr)
            
        while k > 0:
            res.pop()
            k -= 1
        
        while res and res[0] == 0:
            del res[0]
        
        string = ''.join(map(str,res))
        return string if string else 0
        
