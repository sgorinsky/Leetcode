class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        for (int i = 0; i < length; ++i) {
            if (val == nums[i] && length > 0) {
                for (int j = i+1; j < length; ++j) {
                    nums[j-1] = nums[j];
                }
                --length, --i;
            }
        }
        return length;
    }
};
