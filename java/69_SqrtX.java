class Solution {
    public int mySqrt(int x) {
        if (x == 1) return x;
        int left = 1, right = x / 2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long squared = (long) mid * mid;
            if (squared == x) return mid;
            else if (squared > x) right = mid - 1;
            else left = mid + 1;
        }
        return right;
    }
}
