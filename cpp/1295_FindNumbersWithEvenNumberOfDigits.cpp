class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int n : nums) {
            int iterations = 0;
            while (n > 0) {
                n = floor(n/10);
                ++iterations;
            }
            if (iterations % 2 == 0) ++count;
        }
        return count;
    }
};
