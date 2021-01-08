class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        letters = [-1] * 128
        high = idx = 0
        for i, c in enumerate(s):
            if letters[ord(c)] >= 0:
                idx = max(letters[ord(c)] + 1, idx)
            high = max(i - idx + 1, high)
            letters[ord(c)] = i
        return high

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        start = high = count = 0
        letters = {}
        
        for index, i in enumerate(s):
            if i in letters and letters[i] >= start:
                high, count, start = max(high, count), index - letters[i], letters[i]+1
            else:
                count += 1
            letters[i] = index
        return max(high, count)
