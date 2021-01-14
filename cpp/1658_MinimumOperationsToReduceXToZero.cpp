class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int N = nums.size(), count = INT_MAX, curr = 0, i = -1;
        
        // furthest from left we can go
        while (curr < x && ++i < N) 
            curr += nums[i];
        
        if (curr == x) count = i + 1;
        else if (i >= N) return -1;
        
        int j = N - 1;
        // how far from right
        while (j >= 0) {
            curr += nums[j--];
            while (i >= 0 && curr > x) 
                curr -= nums[i--];
            
            if (curr == x) count = min(count, i + N - j);
            else if (curr > x && i < 0) break;
        }
        return count == INT_MAX ? -1 : count;
    }
};
