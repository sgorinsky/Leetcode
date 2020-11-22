class Solution {
public:
    string getSmallestString(int n, int k) {
        string start = "";
        int count = 0;
        for (int i = 0; i < n; ++i) {
            start += 'a';
            count++;
        }
        
        int end = n - 1;
        while (count < k) {
            if (k - count >= 26) {
                start[end--] = 'z';
                count += 25;
            } else if (k - count < 26) {
                start[end] = (char) (start[end] + (k - count));
                break;
            }
        }
        return start;
    }
};
