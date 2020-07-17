def longestPalindrome(s: str) -> str:
        high = [0, ''] 
        for i in range(len(s)):
            count = 0
            if high[0] > len(s) - i:
                break
            for j in range(len(s), i, -1):
                substr = s[i:j]
                if j - i < high[0]:
                    break
                if isPalindrome(substr) and j - i > high[0]:
                    high = [j-i, substr]
        return high[1]
    
def isPalindrome(s: string):
    return s == s[::-1]

class Solution:
    def longestPalindrome(self, s: str) -> str:
        longest_count, longest_string, string_length = 0, '', len(s)
        for i, char in enumerate(s):
            # odd strings
            begin, end, curr_count, curr_string = i-1, i+1, 1, s[i]
            while begin >= 0 and end < string_length and s[begin] == s[end]:
                curr_string = s[begin] + curr_string + s[end]
                curr_count += 2
                begin -= 1
                end += 1
            if curr_count > longest_count:
                longest_count, longest_string = curr_count, curr_string
            # even strings
            begin, end, curr_count, curr_string = i, i+1, 0, ''
            while begin >= 0 and end < string_length and s[begin] == s[end]:
                curr_string = s[begin] + curr_string + s[end]
                curr_count += 2
                begin -= 1
                end += 1
            if curr_count > longest_count:
                longest_count, longest_string = curr_count, curr_string
        return longest_string
