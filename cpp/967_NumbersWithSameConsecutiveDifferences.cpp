class Solution {
public:
    unordered_set<int> result_set;
    int n;
    int k;
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> result = {};
        if (N <= 1) {
            for (int i = 0; i <= 9; ++i) 
                result.push_back(i);
            
            return result;
        }
        
        n = N;
        k = K;

        for (int i = 1; i <= 9; ++i) {
            addDigits(i, i);
        }
        
        for (int cand : result_set) {
            result.push_back(cand);
        }
        return result;
    }
    
    void addDigits(int cand, int d, int count = 1) {
        if (count == n) {
            result_set.insert(cand);
            return;
        } 
        
        if (d-k >= 0) {
            int digit = d - k;
            addDigits(cand * 10 + digit, d-k, count+1);
        }
          
        if (d+k <= 9) {
            int digit = d + k;
            addDigits(cand * 10 + digit, d+k, count+1);
        }
    }
};


