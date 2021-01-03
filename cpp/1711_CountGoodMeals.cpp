class Solution {
public:
    int high = 1000000007;
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, int> nums;
        int count = 0;
        for (int n : deliciousness) {
            if (nums.find(n) == nums.end()) nums[n] = 1;
            else nums[n] += 1;
            int p = 1;
            for (int i = 1; i <= 22; ++i) {
                int l = (p - n) % high;
                p *= 2;
                if (nums.find(l) != nums.end()) {
                    if (n == l) {
                        count += nums[n] - 1;
                    } else {
                        count += nums[l];
                    }
                    count %= high;
                }
            }
        }
        return count;
    }
};
