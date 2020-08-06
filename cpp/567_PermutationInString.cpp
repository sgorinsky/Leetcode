class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        
        vector<int> s1_lets(26, 0);
        
        for (char c : s1) ++s1_lets[(int) (c - 'a')];
        
        int m = s1.length();
        int n = s2.length();
        
        vector<int> check_lets(26, 0);
        for (int i = 0; i < m; ++i) ++check_lets[(int) (s2[i] - 'a')];
        
        for (int i = m; i < n; ++i) {
            if (check_lets == s1_lets) return true;
            
            ++check_lets[(int) (s2[i] - 'a')], --check_lets[(int) (s2[i-m] - 'a')];
        }
        return check_lets == s1_lets;
    }
};
