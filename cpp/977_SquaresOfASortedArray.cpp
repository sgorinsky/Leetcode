class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> neg_stack;
        int idx = 0; 
        int num_negs = 0;
        
        while (idx < A.size() && A[idx] < 0) {
            neg_stack.push_back(A[idx]*A[idx]);
            ++idx, ++num_negs;
        }

        vector<int> res;
        for (int i = num_negs; i < A.size(); ++i) {
            int square = A[i] * A[i];
            while (!neg_stack.empty() && square > neg_stack.back()) {
                res.push_back(neg_stack.back());
                neg_stack.pop_back();
            }
            res.push_back(square);
        }
        while (!neg_stack.empty()) {
            res.push_back(neg_stack.back());
            neg_stack.pop_back();
        }
        return res;
    }
};
