class Solution {
    public String getSmallestString(int n, int k) {
        char[] res = new char[n];
        for (int i = 0; i < n; ++i) res[i] = 'a';
        
        int score = n;
        int end = n - 1;
        while (score < k) {
            if (k - score >= 26) {
                res[end--] = 'z';
                score += 25;
            } else if (k - score < 26) {
                res[end] = (char) (res[end] + k - score);
                break;
            }
        }
        return new String(res);
    }
}
