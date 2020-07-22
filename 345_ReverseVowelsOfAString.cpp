class Solution {
public:
    string reverseVowels(string s) {
        string str = "";
        vector<char> vowel_stack = {};
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < s.length(); ++i) {
            if (vowels.find(tolower(s[i])) != vowels.end()) {
                vowel_stack.push_back(s[i]);
            }
        }
        for (int i = 0; i < s.length(); ++i) {
            if (vowels.find(tolower(s[i])) != vowels.end()) {
                str += vowel_stack[vowel_stack.size()-1];
                vowel_stack.pop_back();
            } else {
                str += s[i];
            }
        }
        return str;
    }
};
