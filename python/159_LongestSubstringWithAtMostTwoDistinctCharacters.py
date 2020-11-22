class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        letter_counts = {chr(ord(c) + i): 0 for c in ['a', 'A'] for i in range(26)}
        distincts = max_length = length = trail_idx = 0
        
        for i, c in enumerate(s):
            letter_counts[c] += 1
            length += 1
            if letter_counts[c] == 1:
                distincts += 1
            while distincts > 2:
                letter_counts[s[trail_idx]] -= 1
                length -= 1
                if letter_counts[s[trail_idx]] == 0:
                    distincts -= 1
                trail_idx += 1
            max_length = max(max_length, length)
            
        return max_length
