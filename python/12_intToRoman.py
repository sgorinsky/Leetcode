def intToRoman(num: int) -> str:
        roman_ints = {
            1: 'I',
            4: 'IV',
            5: 'V',
            9: 'IX',
            10: 'X',
            40: 'XL',
            50: 'L',
            90: 'XC',
            100: 'C',
            400: 'CD',
            500: 'D',
            900: 'CM',
            1000: 'M'
        }
        roman_string = ''
        num_array = []
        i = 10
        while num > 0:
            num_array.append(num%10)
            num //= 10
        for i in range(len(num_array)):
            if num_array[i]*(10**i) == 0:
                pass
            elif num_array[i]*(10**i) in roman_ints:
                roman_string = roman_ints[num_array[i]*(10**i)]  + roman_string
            else:
                sub_string = ''
                while num_array[i]*10**i not in roman_ints:
                    sub_string += roman_ints[10**i]
                    num_array[i] -= 1
                roman_string = roman_string + roman_ints[num_array[i]] + sub_string
        return roman_string
