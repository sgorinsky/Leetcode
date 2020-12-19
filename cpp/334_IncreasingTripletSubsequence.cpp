class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<vector<int>> stacks = {{nums[0]}};
        for (int i = 1; i < nums.size(); ++i) {
            int n = nums[i];
            for (int j = 0; j < stacks.size(); ++j) {
                vector<int> &stack = stacks[j];
                if (n < stack.back() && (stack.size() == 1 || n > stack[0])) {
                    stack[stack.size() - 1] = n;
                    break;
                } else if (n < stack[0] && j == stacks.size() - 1) {
                    stacks.push_back({n});
                    break;
                } else if (n > stack.back()) {
                    stack.push_back(n);
                    if (stack.size() == 3) return true;
                    break;
                }
            }
        }
        return false;
    }
};
