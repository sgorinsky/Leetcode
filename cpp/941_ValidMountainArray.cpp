class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int N = A.size();
        if (N <= 2) 
            return false;
        
        bool isIncreasing = true;
        for (int i = 1; i < N; ++i) {
            if (isIncreasing) {
                if (A[i] == A[i-1]) {
                    return false;
                } else if (A[i] < A[i-1]) {
                    isIncreasing = false;
                }
            } else {
                if (A[i] >= A[i-1]) {
                    return false;
                }
            }
        }
        return A[0] < A[1] && A[N-1] < A[N-2];
    }
};
