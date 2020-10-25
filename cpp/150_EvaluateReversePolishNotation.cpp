class Solution {
public:
    unordered_set<string> operations = {
        {"+"},
        {"-"},
        {"*"},
        {"/"}
    };

    int evalRPN(vector<string>& tokens) {
        vector<string> stack;
        int a, b;
        int total = 0;
        for (string t : tokens) {
            if (operations.find(t) != operations.end()) {
                b = stoi(stack.back());
                stack.pop_back();
                a = stoi(stack.back());
                stack.pop_back();
                
                if (t == "+") total = a + b;
                else if (t == "-") total = a - b;
                else if (t == "*") total = a * b;
                else if (a == 0 || b == 0) total = 0;
                else total = a / b;
                
                stack.push_back(to_string(total));
            } else {
                stack.push_back(t);
            }
        }
        return stoi(stack.back());
    }
};
