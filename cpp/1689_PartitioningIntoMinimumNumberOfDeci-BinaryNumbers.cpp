class Solution {
public:
    int minPartitions(string n) {
        if (n.empty()) return 0;
        int high = 1;
        for (char c : n) {
            high = max(c - '0', high);
        }
        return high;
    }
};
