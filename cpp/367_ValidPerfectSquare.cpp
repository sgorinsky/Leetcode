class Solution {
public:
    int MAX_RIGHT = 46340;
    bool isPerfectSquare(int num) {
        int left = 0, right = num < MAX_RIGHT ? num : MAX_RIGHT;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long cand = mid * mid;
            if (cand == num)
                return true;
            else if (cand > num)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};

class Solution {
public:
    bool isPerfectSquare(int num) {
        int root = (int) sqrt(num);
        return root * root == num;
    }
};
