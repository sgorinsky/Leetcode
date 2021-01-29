class Solution {
public:
    string getSmallestString(int n, int k) {
        char *res = new char[n];
        for (int i = n - 1; i >= 0; --i) {
            int idx = i + 1;
            if (idx == k) {
                res[i] = 'a';
                k--;
            } else if (k - idx < 26) {
                res[i] = 'a' + k - idx;
                k = i;
            } else {
                res[i] = 'z';
                k -= 26;
            };
        }
        return string(res, n);
    }
};

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
