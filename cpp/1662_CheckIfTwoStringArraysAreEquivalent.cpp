class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int idx1 = 0, idx2 = 0;
        int a = 0, b = 0;
        while (idx1 < word1.size() && idx2 < word2.size()) {
            while (a < word1[idx1].length() && b < word2[idx2].length()) {
                if (word1[idx1][a++] != word2[idx2][b++]) return false;
            }
            if (a >= word1[idx1].length()) idx1++, a = 0;
            if (b >= word2[idx2].length()) idx2++, b = 0;
        }
        return idx1 == word1.size() && idx2 == word2.size();
    }
};

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
