class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int N = nums.size();
        vector<int> left_sums(N, 0);
        vector<int> right_sums(N, 0);
        for (int i = 1; i < N; ++i) {
            left_sums[i] = nums[i] + (i - 2 >= 0 ? left_sums[i - 2] : 0);
            left_sums[i - 1] = nums[i - 1] + (i - 3 >= 0 ? left_sums[i - 3] : 0);
            
            right_sums[N - i] = nums[N - i] + (N - i + 2 < N ? right_sums[N - i + 2] : 0);
            right_sums[N - i - 1] = nums[N - i - 1] + (N - i + 1 < N ? right_sums[N - i + 1] : 0);
        }
        
        int count = 0;
        for (int i = 0; i < N; ++i) {
            int even = 0, odd = 0;
            if (i % 2 == 0) {
                even = i - 2 >= 0 ? left_sums[i - 2] : 0;
                odd = i - 1 >= 0 ? left_sums[i - 1] : 0;
                
                even += (i + 1 < N ? right_sums[i + 1] : 0);
                odd += (i + 2 < N ? right_sums[i + 2] : 0);
            } else {
                even = i - 1 >= 0 ? left_sums[i - 1] : 0;
                odd = i - 2 >= 0 ? left_sums[i - 2] : 0;
                
                even += (i + 2 < N ? right_sums[i + 2] : 0);
                odd += (i + 1 < N ? right_sums[i + 1] : 0);
            }
            
            if (even == odd) count++;
        }
        return count;
    }
};
