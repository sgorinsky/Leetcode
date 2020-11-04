class Solution:
    digits = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'}
    def decodeString(self, s: str) -> str:
        stack = []
        res = ''
        for i, c in enumerate(s):
            if c == ']':
                curr_string = ''
                while stack and stack[-1] != '[':
                    curr_string += stack.pop()
                
                stack.pop() # get rid of [
                
                num, count = 0, 0
                while stack and stack[-1] in digits:
                    num = int(stack.pop()) * 10**count + num
                    count += 1
                    
                for i in range(num):
                    for j in range(len(curr_string) - 1, -1, -1):
                        stack.append(curr_string[j])
            else:
                stack.append(c)
                
        return ''.join(stack)
                    
