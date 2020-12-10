class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3 || arr[0] > arr[1]) return false;
        bool increasing = true;
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i] == arr[i + 1]) return false;
            if (increasing) {
                if (arr[i] > arr[i + 1]) increasing = false;
            } else {
                if (arr[i] <= arr[i + 1]) return false;
            }
        }
        return !increasing;
    }
};

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
