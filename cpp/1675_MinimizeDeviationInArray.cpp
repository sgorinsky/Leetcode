class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> evens;
        int small = INT_MAX;
        for (int n : nums) {
            n = n % 2 == 0 ? n : n * 2;
            small = min(n, small);
            evens.push(n);
        }
        
        int deviation = INT_MAX;
        while (!evens.empty()) {
            int n = evens.top();
            evens.pop();
            deviation = min(deviation, n - small);
            if (n % 2 == 0) {
                evens.push(n / 2);
                small = min(small, n / 2);
            } else {
                break;
            }
        }
        return deviation;
    }
};
