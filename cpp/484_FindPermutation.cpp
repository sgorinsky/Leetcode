class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> stack = {}, res = {};
        int N = s.length()+1;
        for (int i = 0; i < N; ++i) {
            if (s[i] == 'D') {
                stack.push_back(i+1);
            } else {
                res.push_back(i+1);
                while (!stack.empty()) {
                    res.push_back(stack.back());
                    stack.pop_back();
                }
            }
        }
        return res;
    }
};
