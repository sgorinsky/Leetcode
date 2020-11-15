from collections import Counter
class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        char_counts1 = Counter(word1)
        char_counts2 = Counter(word2)
        
        set1, set2 = set(), set()
        for k, v in char_counts1.items():
            if k not in char_counts2: return False
            set1.add(v)
            
        for k, v in char_counts2.items():
            if k not in char_counts1: return False
            set2.add(v)
            
        for count in set1:
            if count not in set2: return False
        
        for count in set2:
            if count not in set1: return False
            
        return True
