class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if (pattern == "" || str == "")
            return false;
        
        unordered_map<char, string> char_map;
        unordered_map<string, char> word_map;
        istringstream ss(str);
        string word;
        int i = 0;
        
        while (ss >> word) {
            char c = pattern[i++];
            if (char_map.find(c) == char_map.end() && word_map.find(word) == word_map.end()) {
                char_map[c] = word;
                word_map[word] = c;
            }
            else
                if (i > pattern.length() || char_map[c] != word || word_map[word] != c)
                    return false;
        }
        return i == pattern.length() || pattern.length() == 1;
    }
};
