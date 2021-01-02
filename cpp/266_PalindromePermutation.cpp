class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> letters(126, 0);
        for (char c : s) {
            letters[c] += 1;
        }
        
        int tolerance = s.size() % 2;
        for (int n : letters) {
            if (n % 2 != 0 && --tolerance < 0) 
                return false;
        }
        return true;
    }
};
