class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int count = 0, idx = 0, N = arr.size();
        for (int i = 1; i <= 2000; ++i) {
            if (idx >= N || arr[idx] != i) count++;
            else idx++;
            if (count == k) return i;
        }
        return 1000;
    }
};
