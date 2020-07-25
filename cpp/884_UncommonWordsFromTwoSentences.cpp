class Solution {
public:
    unordered_map<string, int> word_counts;
    vector<string> uncommonFromSentences(string A, string B) {
        if (A != "" && B != ""){
            A += " " + B;
        } else {
            A = A != "" ? A : B;
        }
        
        vector<string> words = split_by_space(A);
        for (string word : words) word_counts[word] = word_counts.find(word) == word_counts.end() ? 1 : word_counts[word] + 1;
        
        vector<string> res;
        for (const auto& entry : word_counts) {
            if (entry.second == 1) res.push_back(entry.first);
        }
        return res;
    }
    
    vector<string> split_by_space(string str) {
        vector<string> res;
        string curr = "";
        for (char c : str) {
            if (c == ' ') {
                res.push_back(curr);
                curr = "";
            } else {
                curr += c;
            }
        }
        res.push_back(curr);
        return res;
    }
};
