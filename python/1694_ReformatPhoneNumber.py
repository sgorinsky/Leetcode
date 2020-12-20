class Solution:
    def reformatNumber(self, number):
        output = []
        number = number.replace("-", "").replace(" ", "")
        length = len(number)
        i = 0
        while i < length:
            if i+4 == length:
                output.append(number[i:i+2])
                i += 2
            elif i+3 <= length:
                output.append(number[i:i+3])
                i += 3
            else:
                output.append(number[i:i+2])
                i += 2
                
        return output[0] if len(output) < 1 else "-".join(output)
