class Solution {
public:
    unordered_map<char, char> close_parens = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    bool isValid(string s) {
        vector<char> stack;
        for (int i = 0; i < s.length(); ++i) {
            bool closed_paren = close_parens.find(s[i]) != close_parens.end();
            if (stack.empty() || !closed_paren) stack.push_back(s[i]);
            else {
                if (close_parens.find(stack.back()) == close_parens.end() && close_parens[s[i]] == stack.back()) stack.pop_back();
                else return false;
            }
        }
        return stack.empty();
    }
};
