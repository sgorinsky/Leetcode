class Solution {
public:
    string longestPalindrome(string s) {
        int high = 0;
        pair<int, int> widest = {0, 0};
        for (int i = 0; i < s.length(); ++i) {
            pair<int, int> middle = checkIndices(s, i, i + 1);
            pair<int, int> ends = checkIndices(s, i, i);
            
            if (ends.second - ends.first > widest.second - widest.first) widest = ends;
            if (middle.second - middle.first > widest.second - widest.first) widest = middle;
        }
        return s.substr(widest.first, widest.second - widest.first + 1);
    }
    
    pair<int, int> checkIndices(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) left--, right++;
        return {left + 1, right - 1};
    }
};
