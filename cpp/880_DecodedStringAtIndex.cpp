class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long int size = 0;
        for (char c : S) {
            int d = c - '0';
            if (d >= 0 && d <= 9) {
                size *= d;
            } else {
                size++;
            }
        }
        
        string res = "";
        for (int i = S.length() - 1; i >= 0; --i) {
            char c = S[i];
            int d = c - '0';
            K %= size;
            if (d >= 0 && d <= 9) {
                size /= d;
            } else {
                if (K == 0) return res + c;
                size--;
            }
        }
        return res + S[0];
    }
};
