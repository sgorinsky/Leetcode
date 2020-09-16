class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.trie = {}
        self.end = False
        

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        node = self
        for l in word:
            if l not in node.trie:
                node.trie[l] = Trie()
            node = node.trie[l]
        node.end = True

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        node = self
        for l in word:
            if l in node.trie:
                node = node.trie[l]
            else:
                return False
        return node.end

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        node = self
        for p in prefix:
            if p in node.trie:
                node = node.trie[p]
            else:
                return False
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)

class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.trie_set = set()
        self.trie_list = []
        

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        self.trie_set.add(word)
        self.trie_list.append(word)
        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        return word in self.trie_set
        

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        for word in self.trie_list:
            if word[:len(prefix)] == prefix:
                return True
        return False
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
