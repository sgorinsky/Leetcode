class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> subseq;
        for (int n : nums) {
            if (subseq.empty() || n > subseq.back()) subseq.push_back(n);
            else {
                for (int i = 0; i < subseq.size(); ++i) {
                    if ((n < subseq[i] && i == 0) || 
                        (n < subseq[i] && n > subseq[i-1])) {
                        subseq[i] = n;
                        break;
                    }
                }
            }
        }
        return subseq.size();
    }
};
