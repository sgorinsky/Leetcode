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
