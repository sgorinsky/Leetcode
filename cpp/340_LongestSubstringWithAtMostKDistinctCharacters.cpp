class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int high = 0, count = 0, distinct = 0, trail = 0;
        vector<int> letters(126, 0);
        for (int i = 0; i < s.size(); ++i) {
            count++;
            if (++letters[s[i]] == 1) distinct++;
            if (distinct > k) {
                while (trail <= i && distinct > k) {
                    letters[s[trail]]--;
                    if (letters[s[trail++]] == 0) distinct--;
                    count--;
                }
            }
            high = max(count, high);
        }
        return high;
    }
};

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
