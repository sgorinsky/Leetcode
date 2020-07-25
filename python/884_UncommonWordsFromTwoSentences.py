class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        both_lists, word_counts = A.split(' ') + B.split(' '), {}
        for word in both_lists:
            if word:
                word_counts[word] = 1 if word not in word_counts else word_counts[word]+1
            
        res = []
        for word, count in word_counts.items():
            if count == 1:
                res.append(word)
        return res
