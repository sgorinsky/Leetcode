class Solution {
public:
    unordered_map<char, int> letters = {};
    int titleToNumber(string s) {
        for (int i = 0; i < 26; ++i) letters[(char) 'A'+i] = i+1;
        int total = 0, power = s.length()-1;
        
        for (char c : s) total += pow(26, power--) * letters[c];
        return total;
    }
};
