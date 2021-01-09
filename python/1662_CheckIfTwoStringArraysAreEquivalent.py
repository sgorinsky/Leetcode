class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        idx1 = idx2 = a = b = 0
        N, M = len(word1), len(word2)
        while idx1 < N and idx2 < M:
            while a < len(word1[idx1]) and b < len(word2[idx2]):
                if word1[idx1][a] != word2[idx2][b]:
                    return False
                a += 1
                b += 1
            if a >= len(word1[idx1]):
                idx1 += 1
                a = 0
            if b >= len(word2[idx2]):
                idx2 += 1
                b = 0
        
        return idx1 == N and idx2 == M
