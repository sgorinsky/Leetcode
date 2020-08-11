class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), [](const int a, const int b) {
            return a < b;
        });
        
        int N = citations.size();
        int h = 0;
        for (int i = 0; i < N; ++i) {
            int cand = citations[i];
            if (N-cand >= i) {
                h = max(cand, h);
            }
		    if (N-i <= cand) {
                h = max(N-i, h);
            }
            
        }
        return h;
    }
};
