class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int close_sum = -1;
        int left = 0, right = A.size() - 1;
        while (left < right) {
            int cand_sum = A[left] + A[right];
            if (cand_sum >= K) {
                right--;
            } else {
                close_sum = max(cand_sum, close_sum);
                left++;
            }
        }
        return close_sum;
    }
};
