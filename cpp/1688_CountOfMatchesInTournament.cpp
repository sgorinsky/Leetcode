class Solution {
public:
    int numberOfMatches(int n) {
        int sum = 0;
        while (n >= 2) {
            sum += (n / 2);
            n -= (n / 2);
        }
        return sum;
    }
};
