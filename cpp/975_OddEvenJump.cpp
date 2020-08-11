class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        const int N = A.size();
        if (N <= 1) return N;
        
        vector<bool> odd(N, false);
        vector<bool> even(N, false);
        map<int, int> vals = {};
        
        odd[N-1] = even[N-1] = true;
        vals[A[N-1]] = N-1;
        
        for (int i = N-2; i >= 0; --i) {
            if (vals.find(A[i]) != vals.end()) {
                odd[i] = even[vals[A[i]]];
                even[i] = odd[vals[A[i]]];
            } else {
                auto lower = vals.lower_bound(A[i]);
                if (lower-- != vals.begin()) {
                    int l = lower->first;
                    even[i] = odd[vals[l]];
                }
                
                auto higher = vals.lower_bound(A[i]);
                if (higher != vals.end()) {
                    int h = higher->first;
                    odd[i] = even[vals[h]];
                }
                
            }
            vals[A[i]] = i;
        }
        
        int count = 0;
        for (bool b : odd) {
            if (b) ++count;
        }
        return count;
    }
};
