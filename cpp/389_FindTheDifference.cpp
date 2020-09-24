class Solution {
public:
    char findTheDifference(string s, string t) {
        if (t.length() < s.length()) {
            string temp = t;
            t = s;
            s = temp;
        }
        
        unordered_map<char, int> letter_map;
        for (char c : s)
            letter_map[c] = letter_map.find(c) == letter_map.end() ? 1 : letter_map[c] + 1;
        
        for (char c : t) {
            if (letter_map.find(c) == letter_map.end() || letter_map[c] == 0)
                return c;
            else
                letter_map[c]--;
        }
        return s[0];
    }
};
