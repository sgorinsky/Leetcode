class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> results;
        if (nums.empty()) return results;
        int low = nums[0], high = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            if (n > high + 1) {
                string new_string = low == high ? to_string(high) : to_string(low) + "->" + to_string(high);
                results.push_back(new_string);
                low = n, high = n;
            } else {
                high = n;
            }
        }
        results.push_back(low == high ? to_string(high) : to_string(low) + "->" + to_string(high));
        return results;
    }
};
