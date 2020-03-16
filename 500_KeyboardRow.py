class Solution:
    row1 = 'qwertyuiop[]{}'
    row2 = 'asdfghjkl;:\'\"'
    row3 = 'zxcvbnm.,/'
    keyboard = {}
    for l in row1: keyboard[l] = 1
    for l in row2: keyboard[l] = 2
    for l in row3: keyboard[l] = 3
    
    def findWords(self, words: List[str]) -> List[str]:
        
        same_row_words = []
        for word in words:
            add_to_same_row_words = True
            if word: curr_row = self.keyboard[word[0].lower()]
            for l in word:
                if self.keyboard[l.lower()] != curr_row: add_to_same_row_words = False
            if add_to_same_row_words: same_row_words.append(word)
        return same_row_words
        
