class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int high = 0, curr = 0;
        int l = 0;
        unordered_map<int, int> counts, lasts;
        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            curr += n;
            if (counts.find(n) != counts.end() && counts[n] > 0) {
                for (int j = l; j <= lasts[n]; ++j) {
                    curr -= nums[j];
                    counts[nums[j]] -= 1;
                }
                // cout << i << endl;
                // cout << "n: " << n << ", curr: " << curr << endl;
                l = lasts[n] + 1;
            }
            counts[n] = 1;
            lasts[n] = i;
            high = max(high, curr);
        }
        return high;
    }
};

