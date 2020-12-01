class Solution:
    def shortestDistance(self, words: List[str], word1: str, word2: str) -> int:
        idx, jdx, min_dist = 1000000, -1000000, float('inf')
        
        for i, word in enumerate(words):
            if word == word1:
                idx = i
            elif word == word2:
                jdx = i
            min_dist = min(abs(jdx - idx), min_dist)
            
        return min_dist
            
