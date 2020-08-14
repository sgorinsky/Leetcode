class Solution {
public:
    unordered_map<char, int> letter_counts = {};
    int longestPalindrome(string s) {
        for (char c : s) {
            if (letter_counts.find(c) == letter_counts.end()) {
                letter_counts[c] = 1;
            } else {
                ++letter_counts[c];
            }
        }
        
        letter_counts['0'] = 0;
        char curr_greatest_letter = '0';
        
        int greatest_odd = 0;
        int count = 0;
        
        for (auto entry : letter_counts) {
            if (entry.second % 2 == 0) {
                count += entry.second;
            } else {
                if (entry.second > greatest_odd) {
                    count += (entry.second - greatest_odd);
                    greatest_odd = entry.second;
                    if (letter_counts[curr_greatest_letter] > 0) {
                        count += letter_counts[curr_greatest_letter]-1;
                    }
                    curr_greatest_letter = entry.first;
                } else {
                    count += entry.second-1;
                }
                
            }
        }
        return count;
    }
};
