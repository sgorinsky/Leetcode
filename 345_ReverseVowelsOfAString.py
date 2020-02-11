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
