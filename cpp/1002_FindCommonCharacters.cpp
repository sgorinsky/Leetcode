class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        unordered_map<char, int> possible_lets = {};
        vector<string> res = {};
        
        for (char c : A[0]) {
            if (possible_lets.find(c) != possible_lets.end()) ++possible_lets[c];
            else possible_lets[c] = 1;
        }
        
        for (int i = 0; i < A.size(); ++i) {
            for (auto entry : possible_lets) {
                char key = entry.first;
                int val = entry.second;
                auto string_it = A[i].find(key);
                if (i == A.size()-1) {
                    if (string_it != string::npos && possible_lets[key] > 0) {
                        val -= count(A[i].begin(), A[i].end(), key);
                        if (val < 0) val = 0;
                        for (int k = possible_lets[key]; k > val ;--k ) {
                            res.push_back(string{key});
                        }
                    }
                } else if (string_it == string::npos) {
                    possible_lets[key] = -1;
                } else if (val > 1) {
                    val -= count(A[i].begin(), A[i].end(), key);
                    possible_lets[key] = val <= 0 ? entry.second : entry.second - val;
                }
            }
        }
        return res;
        
    }
};
