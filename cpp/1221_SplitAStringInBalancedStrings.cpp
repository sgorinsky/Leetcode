class Solution {
public:
    int balancedStringSplit(string s) {
        int score = 0, count = 0;
        for (char c : s) {
            score += c == 'L' ? 1 : -1;
            if (score == 0) ++count;
        }
        return count;
    }
};
