class Trie {
public:
    unordered_map<char, Trie*> children;
    bool end = false;
    /** Initialize your data structure here. */
    Trie() {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node->children.find(c) == node->children.end())
                node->children[c] = new Trie();
            node = node->children[c];
        }
        node->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node->children.find(c) == node->children.end())
                return false;
            else
                node = node->children[c];
        }
        return node->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end())
                return false;
            else
                node = node->children[c];
        }
        return true;
    }
};
