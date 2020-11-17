class Solution {
public:
    int longestMountain(vector<int>& A) {
        int left = 0, right = 0;
        int high = 0;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] == A[i-1]) left = i;
            else if (A[i] > A[i-1]) continue;
            else {
                if ((i < A.size() - 1 && A[i] < A[i+1])) {
                    high = max(high, i - left + 1);
                    left = i;
                } else right = i;
            }
            
            if (i - 1 > left) {
                high = max(high, right - left + 1);
            } else left = i;
        }
        return high < 3 ? 0 : high;
    }
};
