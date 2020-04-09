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

# O(1) space
class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        i, j = len(S), len(T)
        while i >= 0 and j >= 0:
            i, j = self.findLastNotHash(S, i-1), self.findLastNotHash(T, j-1)
            if (0 > i != j or 0 > j != i) or S[i] != T[j]: return False
        return True
    
    def findLastNotHash(self, s, i):
        hashes = 0
        while i >= 0 and (s[i] == '#' or hashes):
            if s[i] == '#':
                hashes += 1
            else:
                hashes -= 1
            i -= 1
        return i
