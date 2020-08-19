class Solution {
public:
    const unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u',
                                     'A', 'E', 'I', 'O', 'U'};
    
    string toGoatLatin(string S) {
        string res, curr, end;
        istringstream ss(S);
        
        while (ss >> curr) {
            end += 'a';
            
            if (vowels.find(curr[0]) == vowels.end())
                curr = curr.substr(1) + curr[0];
            
            res += curr + "ma" + end + ' ';
        }
        
        res.pop_back(); // remove last space
        return res;
    }
};

class Solution {
public:
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    string toGoatLatin(string s) {
        vector<char> stack = {};
        int i = 0;
        int count = 2;
        string res = "";
        string curr = "";
        s += ' ';
        
        while (i < s.length()) {
            if (stack.size() == 0 && (curr.length() == 0 || curr == " ") && vowels.find(s[i]) == vowels.end()) {
                stack.push_back(s[i]);
            } else if (s[i] == ' ' || i == s.length()-1) {
                while (stack.size() > 0) {
                    curr += stack.back();
                    stack.pop_back();
                }
                
                res += curr + "m";
                for (int a = 0; a < count; ++a)
                    res += "a";
                
                ++count;
                curr = " ";
                while (s[i] == ' ')
                    ++i;
                --i;
            } else {
                curr += s[i];
            }
            ++i;
        }
        return res;
    }
};
