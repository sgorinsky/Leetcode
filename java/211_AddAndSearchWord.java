class TrieNode {
    Map<Character, TrieNode> children = new HashMap();
    boolean word = false;
    public TrieNode() {}
}

class WordDictionary {
    TrieNode trie;

    /** Initialize your data structure here. */
    public WordDictionary() {
        trie = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    public void addWord(String word) {
        TrieNode node = trie;
        
        for (char ch : word.toCharArray()) {
            if (!node.children.containsKey(ch)) {
                node.children.put(ch, new TrieNode()); // curr char in children hashtable maps to potential next stage step of trie
            }
            node = node.children.get(ch); // go to next level of trie we just created
        }
        node.word = true; // we traversed end of trie, claim it's a word
    }
    
    public boolean search(String word) {
        return searchInNode(word, trie);
    }
    
        
    /** Returns if the word is in the node. */
    public boolean searchInNode(String word, TrieNode node) {
        for (int i = 0; i < word.length(); ++i) {
            char ch = word.charAt(i);
            if (!node.children.containsKey(ch)) {
                // if the current character is '.'
                // check all possible nodes at this level
                if (ch == '.') {
                    for (char x : node.children.keySet()) {
                        TrieNode child = node.children.get(x);
                        // call function again passing '.' and traversing trie
                        if (searchInNode(word.substring(i + 1), child)) {
                            return true;    
                        }    
                    }   
                }
                // if no nodes lead to answer
                // or the current character != '.'
                return false;    
            } else {
                // if the character is found
                // go down to the next level in trie
                node = node.children.get(ch); 
            }   
        }      
        return node.word;
    }
}
