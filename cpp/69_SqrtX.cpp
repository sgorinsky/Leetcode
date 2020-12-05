class Solution {
public:
    int mySqrt(int x) {
        if (x == 1) return 1;
        int left = 1, right = x / 2;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            long long squared = mid * mid;
            if (squared == x) return mid;
            else if (squared > x) right = mid - 1;
            else left = mid + 1;
        }
        return left - 1;
    }
};
