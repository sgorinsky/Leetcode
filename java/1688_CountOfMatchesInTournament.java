class Solution {
    public int numberOfMatches(int n) {
        if (n == 0 || n == 1) return 0;
        else if (n == 2) return 1;
        int m = n / 2;
        return m + numberOfMatches(n - m);
    }
}
