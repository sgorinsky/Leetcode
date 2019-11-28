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
