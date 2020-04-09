class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        s, t = [], []
        for i in range(len(S)):
            if S[i] == '#':
                if s:
                    del s[-1]
            else: s.append(S[i])

        for i in range(len(T)):
            if T[i] == '#':
                if t:
                    del t[-1]
            else: t.append(T[i])
                
        return s == t
