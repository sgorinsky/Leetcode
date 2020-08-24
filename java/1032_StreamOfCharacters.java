class TrieNode {
    Map<Character, TrieNode> children = new HashMap<>();
    boolean word = false;
    
    public TrieNode() {};
}


class StreamChecker {
    Deque<Character> letters;
    TrieNode trie;
    int maxLength;
    
    public StreamChecker(String[] words) {
        letters = new LinkedList<Character>();
        trie = new TrieNode();
        maxLength = 0;
        
        for (String w : words) {
            TrieNode node = trie;
            int wordLength = w.length();
            for (int i = wordLength-1; i >= 0; --i) {
                char c = w.charAt(i);
                if (!node.children.containsKey(c))
                    node.children.put(c, new TrieNode());
                node = node.children.get(c);
            }
            node.word = true;
            maxLength = w.length() > maxLength ? w.length() : maxLength;
        }
    }

    public boolean query(char l) {
        letters.addFirst(l);
        if (letters.size() > maxLength)
            letters.pollLast();
        
        TrieNode node = trie;
        for (char c : letters) {
            if (node.children.containsKey(c)) {
                node = node.children.get(c);
            } else {
                break;
            }
            
            if (node.word)
                return true;
        }
        return node.word;
            
    }
}

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker obj = new StreamChecker(words);
 * boolean param_1 = obj.query(letter);
 */
