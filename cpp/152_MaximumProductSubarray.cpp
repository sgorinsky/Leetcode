class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int N = nums.size();
        if (N == 0) return 0;
        
        int left = 1, right = 1, high = INT_MIN;
        for (int i = 0; i < N; ++i) {
            int a = nums[i], b = nums[N-i-1]; // a is int from left, b is int from right
            left *= a, right *= b;
            
            high = findMax({ a, b, left, right, high });
            
            if (a == 0) left = 1;
            if (b == 0) right = 1;
        }
        return high;
    }
    
    int findMax(vector<int> vals) {
        int high = INT_MIN;
        for (int n : vals) {
            high = max(n, high);
        }
        return high;
    }
};
