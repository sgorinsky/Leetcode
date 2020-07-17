def romanToInt(s: str) -> int:
        roman_ints = {
            'I':1,
            'IV':4,
            'V':5,
            'IX':9,
            'X':10,
            'XL':40,
            'L':50,
            'XC':90,
            'C':100,
            'CD':400,
            'D':500,
            'CM':900,
            'M':1000, 
        }
        total = 0
        s_length = len(s)
        if len(s) == 0:
            return total
        sub = 0
        for i in range(s_length):
            if (i+1 < s_length and s[i:i+2] in roman_ints):
                sub = roman_ints[s[i:i+2]]
            else:
                total = total + sub if sub > 0 else total + roman_ints[s[i]]
                sub = 0
        return total

print(romanToInt('MCMXCVIII'))
