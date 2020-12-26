class Solution {
public:
    unordered_map<int, int> cache;
    int numDecodings(string s) {
        return helper(0, s);
    }
    
    int helper(int head, string s) {
        if (cache.find(head) != cache.end()) return cache[head];
        else if (head > s.length() || s[head] == '0') return 0;
        else if (head == s.length()) return 1;
        // cout << "head: " << head << ", +2: " << (head + 2) << endl;
        // cout << s.substr(head, 2) << endl;
        cache[head] = helper(head + 1, s);
        if (head + 2 <= s.length()) {
            int slice = stoi(s.substr(head, 2));
            // cout << slice << endl;
            if (slice >= 1 && slice <= 26) {
                cache[head] += helper(head + 2, s);
            }
        }
        return cache[head];
    }
};
