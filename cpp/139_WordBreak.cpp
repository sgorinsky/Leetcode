class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set;
        for (string w : wordDict)
            word_set.insert(w);
        
        deque<int> zero_indices = {0};
        for (int i = 1; i <= s.length(); ++i) {
            for (int idx : zero_indices) {
                if (word_set.find(s.substr(idx, i - idx)) != word_set.end()) {
                    zero_indices.push_front(i);
                    break;
                }
            }
        }
        return zero_indices.front() == s.length();
    }
};
