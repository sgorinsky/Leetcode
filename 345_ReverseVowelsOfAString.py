class Solution:
    def reverseVowels(self, string: str) -> str:
        vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'}
        left, right = 0, len(string) - 1
        s = [letter for letter in string]
        while left < right:
            if not s[left] in vowels:
                left += 1
            if not s[right] in vowels:
                right -= 1
            if s[left] in vowels and s[right] in vowels:
                s[left], s[right] = s[right], s[left]
                left += 1
                right -= 1
        return ''.join(s)

# much worse runtime (still O(N)), slightly better memory
class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'}
        left_str, right_str =  '', ''
        while len(s) > 1:
            if not s[0] in vowels:
                left_str += s[0]
                s = s[1:]
            if not s[len(s)-1] in vowels:
                right_str = s[len(s)-1] + right_str
                s = s[:len(s)-1]
            if len(s) > 1 and s[0] in vowels and s[len(s)-1]  in vowels:
                left_str, right_str = left_str + s[len(s)-1], s[0] + right_str
                s = s[1:len(s)-1]
        return left_str + s + right_str
