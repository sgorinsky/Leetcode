class Solution {
public:
    vector<string> digit_map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"} ;
    vector<string> permutations;
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return permutations;
        
        unordered_set<char> digit_set;
        for (char d : digits) digit_set.insert(d);
        
        helper(0, digits, digit_set, "");
        return permutations;
    }
    
    void helper(int start, string digits, unordered_set<char>& digit_set, string curr) {
        if (curr.length() == digits.length()) {
            permutations.push_back(curr);
            return;
        }
        
        for (int i = start; i < digits.size(); ++i) {
            char d = digits[i];
            int idx = d - '0';
            for (char l : digit_map[idx - 2]) {
                helper(i + 1, digits, digit_set, curr + l);
            }
        }
    }
};
