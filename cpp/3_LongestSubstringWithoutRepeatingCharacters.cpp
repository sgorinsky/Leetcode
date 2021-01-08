class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int high = 0, idx = 0;
        int letters[128] = {};
        for (int i = 0; i < s.length(); ++i) {
            if (++letters[s[i]] > 1) {
                while (letters[s[i]] > 1)
                    letters[s[idx++]]--;
            }
            high = max(high, i - idx + 1);
        }
        return high;
    }
};

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
