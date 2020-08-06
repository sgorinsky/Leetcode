class WordDictionary {
public:
    unordered_map<int, vector<string>> words;
    /** Initialize your data structure here. */
    WordDictionary() {
        words = {};
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        words[word.length()].push_back(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        int m = word.length();
        for (string w : words[m]) {
            int idx = 0;
            while (idx < m && (word[idx] == '.' || w[idx] == word[idx])) ++idx;
            if (idx == m) return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
