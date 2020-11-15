class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) return false;
        unordered_map<char, int> letter1_counts;
        unordered_map<char, int> letter2_counts;
        
        for (int i = 0; i < word1.length(); ++i) {
            letter1_counts[word1[i]] = letter1_counts.find(word1[i]) == letter1_counts.end() ? 1 : letter1_counts[word1[i]] + 1;
            letter2_counts[word2[i]] = letter2_counts.find(word2[i]) == letter2_counts.end() ? 1 : letter2_counts[word2[i]] + 1;
        }
        unordered_map<int, char> counts1, counts2;
        for (auto entry : letter1_counts) {
            if (letter2_counts.find(entry.first) == letter2_counts.end()) return false;
            counts1[entry.second] = entry.first;
        }
        
        for (auto entry : letter2_counts) {
            if (letter1_counts.find(entry.first) == letter1_counts.end()) return false;
            counts2[entry.second] = entry.first;
        }
        
        for (auto entry : counts1) {
            if (counts2.find(entry.first) == counts2.end()) return false;
        }
        
        for (auto entry : counts2) {
            if (counts1.find(entry.first) == counts1.end()) return false;
        }
        return true;
    }
};
