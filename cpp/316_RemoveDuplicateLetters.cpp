class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> letter_counts;
        
        for (char l : s)
            letter_counts[l] = letter_counts.find(l) == letter_counts.end() ? 1 : letter_counts[l] + 1;

        vector<char> stack;
        unordered_set<char> in_stack;
        for (int i = 0; i < s.length(); ++i) {
            if (in_stack.find(s[i]) == in_stack.end()) {
                while (!stack.empty() && s[i] < stack.back() && letter_counts[stack.back()] > 0) {
                    in_stack.erase(stack.back());
                    stack.pop_back();
                }
                stack.push_back(s[i]);
                in_stack.insert(s[i]);
            }
            letter_counts[s[i]]--;
        }
        
        string new_str = "";
        for (char l : stack) new_str += l;
        return new_str;
    }
    
};
