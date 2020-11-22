class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string first = "", second = "";
        for (int i = 0; i < word1.size(); ++i) {
            for (char c : word1[i]) {
                first += c;
            }
        }
        
        for (int i = 0; i < word2.size(); ++i) {
            for (char c : word2[i]) {
                second += c;
            }
        }
        
        return first == second;
    }
};
