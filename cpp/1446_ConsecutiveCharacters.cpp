class Solution {
public:
    int maxPower(string s) {
        if (s.empty()) return 0;
        int high = 1, curr = 1;
        char last = s[0];
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == last) {
                curr++;
            } else {
                last = s[i];    
                curr = 1;
            }
            high = max(high, curr);
        }
        return high;
    }
};
