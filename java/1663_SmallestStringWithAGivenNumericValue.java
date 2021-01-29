class Solution {
    public String getSmallestString(int n, int k) {
        char[] res = new char[n];
        for (int i = n - 1; i >= 0; --i) {
            int idx = i + 1;
            if (idx == k) {
                res[i] = 'a';
                k--;
            } else if (k - idx < 26) {
                int l = 'a' + k - idx;
                res[i] = (char) l;
                k = i;
            } else {
                res[i] = 'z';
                k -= 26;
            }
        }
        return new String(res);
    }
}

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
