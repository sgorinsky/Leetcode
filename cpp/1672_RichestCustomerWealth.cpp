class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int high = 0;
        for (vector<int> account : accounts) {
            int curr = 0;
            for (int n : account) {
                curr += n;
            }
            high = max(curr, high);
        }
        return high;
    }
};
