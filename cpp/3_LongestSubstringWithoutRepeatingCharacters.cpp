class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> symbols;
        int start = 0, count = 0, high = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (symbols.find(c) != symbols.end() && symbols[c] >= start) {
                high = max(high, count);
                count = i - symbols[c];
                start = symbols[c] + 1;
            } else {
                count++;
            }
            symbols[c] = i;
        }
        return max(high, count);
    }
};
