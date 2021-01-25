class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int curr = 10000;
        for (int n : nums) {
            if (n == 1) {
                if (curr < k)
                    return false;
                curr = 0;
            } else {
                curr++;
            }
        }
        return true;
    }
};
