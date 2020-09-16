class Trie {
    HashMap<Character, Trie> trie;
    boolean end;
    /** Initialize your data structure here. */
    public Trie() {
        trie = new HashMap<Character, Trie>();
        end = false;
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        Trie node = this;
        for (int i = 0; i < word.length(); ++i) {
            char c = word.charAt(i);
            if (node.trie.get(c) == null) {
                node.trie.put(c, new Trie());
            }
            node = node.trie.get(c);
        }
        node.end = true;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        Trie node = this;
        for (int i = 0; i < word.length(); ++i) {
            char c = word.charAt(i);
            if (node.trie.get(c) == null) {
                return false;
            } else {
                node = node.trie.get(c);
            }
        }
        return node.end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        Trie node = this;
        for (int i = 0; i < prefix.length(); ++i) {
            char c = prefix.charAt(i);
            if (node.trie.get(c) == null) {
                return false;
            } else {
                node = node.trie.get(c);
            }
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
