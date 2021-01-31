class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int N = nums.size();
        int start = -1, end = N - 1;
        for (int i = N - 2; i >= 0; --i) {
            if (nums[i] < nums[i+1]) {
                int small = INT_MAX;
                start = i;
                for (int j = i + 1; j < N; ++j) {
                    if (nums[i] < nums[j] && nums[j] <= small) {
                        small = nums[j];
                        end = j;
                    }
                }
                break;
            }
        }
        
        if (start >= 0) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
        }
        
        reverse(nums, start + 1, N - 1);
    }
    
    void reverse(vector<int>& nums, int i, int j) {
        while (i <= j) {
            int temp = nums[i];
            nums[i++] = nums[j];
            nums[j--] = temp;
        }
    }
};
