class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (s.length()*k == 0) return 0;
        
        unordered_map<int, int> let_counts;
        int k_count = 0, trailing_idx = 0, high_count = 1;
        for (int i = 0; i < s.length(); ++i) {
            if (let_counts.find(s[i]) == let_counts.end() || let_counts[s[i]] == 0) {
                ++k_count;
                let_counts[s[i]] = 1;
            } else {
                let_counts[s[i]]++;
            }
            
            while (trailing_idx < s.length() && k_count > k) {
                char first = s[trailing_idx];
                while (trailing_idx < s.length() && first == s[trailing_idx]) ++trailing_idx, --let_counts[first];
                if (let_counts[first] == 0) --k_count;
            }
            if (high_count < i-trailing_idx+1) high_count = i-trailing_idx+1;
        }
        return high_count;
    }
};
