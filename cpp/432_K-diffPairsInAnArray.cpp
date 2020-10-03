class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> num_counts;
        int count = 0;
        for (int n : nums) {
            num_counts[n] = num_counts.find(n) == num_counts.end() ? 1 : num_counts[n] + 1;
            if (k == 0 && num_counts[n] == 2) ++count;
            else if (k != 0) {
                if (num_counts[n] == 1) {
                    if (num_counts.find(n + k) != num_counts.end()) ++count;
                    if (num_counts.find(n - k) != num_counts.end()) ++count;
                }
            }
        }
        return count;
    }
};
