class Solution {
public:
    unordered_set<char> ops = {'+', '-', '*', '/'};
    int calculate(string s) {
        deque<int> nums;
        deque<char> operations;
        
        string curr = "";
        for (char c : s) {
            if (c == ' ') continue;
            else if (ops.find(c) == ops.end()) curr += c;
            else {
                int n = stoi(curr);
                if (!operations.empty() && (operations.back() == '*' || operations.back() == '/')) {
                    char op = operations.back();
                    operations.pop_back();
                    
                    if (op == '*') nums[nums.size() - 1] *= n;
                    else nums[nums.size() - 1] /= n;
                } else {
                    nums.push_back(n);
                }
                operations.push_back(c);
                curr = "";
            }
        }
        
        if (!operations.empty() && (operations.back() == '*' || operations.back() == '/')) {
            int n = stoi(curr);
            char op = operations.back();
            operations.pop_back();

            if (op == '*') nums[nums.size() - 1] *= n;
            else nums[nums.size() - 1] /= n;
        } else nums.push_back(stoi(curr));
    
        while (nums.size() > 1) {
            int n = nums.front();
            nums.pop_front();
            char op = operations.front();
            operations.pop_front();
            
            if (op == '+') n += nums[0];
            else if (op == '-') n -= nums[0];
            else if (op == '*') n *= nums[0];
            else n /= nums[0];
            nums[0] = n;
        }
        return nums[0];
    }
};
