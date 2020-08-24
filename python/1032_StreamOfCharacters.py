class TrieNode:
    def __init__(self):
        self.children = {}
        self.word = False

class StreamChecker:
    def __init__(self, words: List[str]):
        self.trie = TrieNode()
        self.letters = deque()
        self.max_length = 0
        for w in words:
            node = self.trie
            for i in range(len(w)-1, -1, -1):
                c = w[i]
                if c not in node.children:
                    node.children[c] = TrieNode()
                node = node.children[c]
                
            node.word = True
            self.max_length = max(self.max_length, len(w))

    def query(self, l: str) -> bool:
        self.letters.appendleft(l)
        if len(self.letters) > self.max_length:
            self.letters.pop()
        
        node = self.trie
        for l in self.letters:
            if l in node.children:
                node = node.children[l]
            else:
                break
            if node.word:
                return True
        return node.word
            
# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)
