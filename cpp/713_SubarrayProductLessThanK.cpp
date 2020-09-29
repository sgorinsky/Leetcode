class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0, trail = 0, product = 1;
        for (int i = 0; i < nums.size(); ++i) {
            product *= nums[i];
            
            while (product >= k && trail < i)
                product /= nums[trail++];
            
            if (product < k)
                count += (i - trail + 1);
            
        }
        return count;
    }
};
