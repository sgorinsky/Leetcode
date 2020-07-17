class Solution:
    phone_numbers = {
        '2': ['a','b','c'],
        '3': ['d','e','f'],
        '4': ['g','h','i'],
        '5': ['j','k','l'],
        '6': ['m','n','o'],
        '7': ['p','q','r','s'],
        '8': ['t','u','v'],
        '9': ['w','x','y','z']
    }
    def letterCombinations(self, digits: str) -> List[str]:
        combinations = set()
        if not digits:
            return combinations
        def helper(current_str, current_digit, max_length):
            if len(current_str) == max_length:
                combinations.add(current_str)
            elif len(current_str) > max_length:
                pass
            else:
                for i in self.phone_numbers[current_digit[0]]:
                    current_str += i
                    helper(current_str, current_digit[1:], max_length)
                    current_str = current_str[:-1]
        helper('', digits, len(digits))
        return combinations
