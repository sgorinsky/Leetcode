class Solution:
    codes = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        return len({ ''.join([self.codes[ord(c) - ord('a')] for c in word]) for word in words })
