class Solution {
public:
    vector<string> parentheses;
    vector<string> generateParenthesis(int n) {
        helper("", 0, 0, n);
        return parentheses;
    }
    
    void helper(string curr, int left, int right, int n) {
        if (curr.length() == 2 * n) parentheses.push_back(curr);
        else {
            if (left < n) helper(curr + "(", left + 1, right, n);
            if (right < left) helper(curr + ")", left, right + 1, n);
        }
    }
};
