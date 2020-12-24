class Solution {
public:
    unordered_map<int, int> letter_counts;
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int trail_idx = 0, char_count = 0, curr_length = 0, max_length = 0;
        for (char c : vector<char>('a', 'A')) {
            for (int i = 0; i < 26; ++i) {
                letter_counts[c + i] = 0;
            }
        }
        for (int i = 0; i < s.size(); ++i) {
            curr_length++;
            if (++letter_counts[s[i] - 'A'] == 1) char_count++;
            while (char_count > 2) {
                curr_length--;
                if (--letter_counts[s[trail_idx++] - 'A'] == 0) char_count--;
            }
            max_length = max(curr_length, max_length);
        }
        return max_length;
    }
};
