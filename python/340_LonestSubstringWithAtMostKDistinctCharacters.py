class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        if s == '' or k == 0 :
            return 0
        
        count, k_count, trailing_idx, curr_letter_counts = 1, 0, 0, {}
        for i, l in enumerate(s):
            if l not in curr_letter_counts or curr_letter_counts[l] == 0:
                curr_letter_counts[l] = 1
                k_count += 1
            else:
                curr_letter_counts[l] += 1
            
            while trailing_idx < len(s) and k_count > k:
                if trailing_idx < len(s):
                    first = s[trailing_idx]
                while trailing_idx < len(s) and first == s[trailing_idx]:
                    trailing_idx += 1
                    curr_letter_counts[first] -= 1
                if curr_letter_counts[first] == 0:
                    k_count -= 1
                
            if i-trailing_idx+1 > count:
                count = i-trailing_idx+1
        return count
