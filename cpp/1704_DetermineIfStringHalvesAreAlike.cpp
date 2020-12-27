class Solution {
public:
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    bool halvesAreAlike(string s) {
        int a = 0, b = 0;
        int i = 0, j = s.length() / 2;
        for (int x = 0; x < s.length() / 2; ++x) {
            if (vowels.find(s[i++]) != vowels.end()) a++;
            if (vowels.find(s[j++]) != vowels.end()) b++;
        }
        return a == b;
    }
};
