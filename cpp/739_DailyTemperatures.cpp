class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<pair<int, int>> stack;
        vector<int> results(T.size(), 0);
        for (int i = 0; i < T.size(); ++i) {
            int temp = T[i];
            if (!stack.empty() && temp > stack.back().second) {
                while (!stack.empty() && temp > stack.back().second) {
                    results[stack.back().first] = i - stack.back().first;
                    stack.pop_back();
                }
            }
            stack.push_back({i, temp});
        }
        return results;
    }
};
