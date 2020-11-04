class Solution:
    def maxPower(self, s: str) -> int:
        if not s: return 0
        
        last_char, high, curr_count = s[0], 1, 1
        for i in range(1, len(s)):
            if last_char == s[i]:
                curr_count += 1
                high = max(curr_count, high)
            else:
                last_char = s[i]
                curr_count = 1
        return high
