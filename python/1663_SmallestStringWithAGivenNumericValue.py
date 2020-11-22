class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        res = ['a'] * n
        score, end = n, n - 1
        
        while score < k:
            if k - score >= 26:
                res[end] = 'z'
                score += 25
                end -= 1
            elif k - score < 26:
                res[end] = chr(ord('a') + k - score)
                break
        
        return ''.join(res)
