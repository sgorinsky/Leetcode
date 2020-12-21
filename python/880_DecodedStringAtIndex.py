class Solution:
    def decodeAtIndex(self, S: str, K: int) -> str:
        size = 0
        for c in S:
            if c.isnumeric():
                size *= int(c)
            else:
                size += 1
        
        for i in range(len(S) - 1, -1, -1):
            K %= size
            if S[i].isnumeric():
                size /= int(S[i])
            else:
                if K == 0: return S[i]
                size -= 1
        return S[0]
