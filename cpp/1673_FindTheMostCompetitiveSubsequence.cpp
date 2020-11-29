class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> stack;
        int i = 0;
        while (i < N) {
            int n = nums[i++];
            if (!stack.empty() && n < stack.back() && i < N - (k - stack.size()) + 1) {
                while (!stack.empty() && stack.size() + (N - i) >= k && stack.back() > n) stack.pop_back();
            }
            stack.push_back(n);
        }
        while (stack.size() > k) stack.pop_back();
        return stack;
    }
};
