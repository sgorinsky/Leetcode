class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        def helper(start, end):
            if end < k: return 0
            
            counts = [0] * 26
            for i in range(start, end): counts[ord(s[i]) - ord('a')] += 1
            for i in range(start, end):
                if counts[ord(s[i]) - ord('a')] < k:
                    mid = i + 1
                    while mid < end and counts[ord(s[mid]) - ord('a')] < k: mid += 1
                    return max(helper(start, i), helper(mid, end))
            
            return end - start
        
        return helper(0, len(s))
