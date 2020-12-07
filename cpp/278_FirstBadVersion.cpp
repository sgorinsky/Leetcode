// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            bool bad = isBadVersion(mid);
            
            if (bad) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
