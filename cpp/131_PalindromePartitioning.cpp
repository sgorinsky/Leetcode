class Solution {
public:
    vector<vector<string>> palindromes;
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        helper(curr, s, 0);
        return palindromes;
    }
    
    void helper(vector<string>& curr, string s, int start) {
        if (start >= s.length()) {
            palindromes.push_back(curr);
            return;
        }
        
        for (int i = start; i < s.length(); ++i) {
            if (isPalindrome(s, start, i)) {
                curr.push_back(s.substr(start, i - start + 1));
                helper(curr, s, i + 1);
                curr.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
};
