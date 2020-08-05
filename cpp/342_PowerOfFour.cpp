class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num == 1) return true;
        int start = 1;
        while (start <= num && start < 1073741824) {
            start *= 4;
            if (start == num) return true;
        }
        return false;
    }
};
