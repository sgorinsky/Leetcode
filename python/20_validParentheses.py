def isValid(self, s: str) -> bool:
        full_length = len(s)
        if full_length&1:
            return False
        lefts = {'(','[','{'}
        left_side_array = []
        
        match = {
            '(':')',
            '[':']',
            '{':'}'
        }
        
        for i in range(full_length):
            if s[i] in lefts:
                left_side_array.append(s[i])
            else:
                if len(left_side_array) == 0 or s[i] != match[left_side_array[-1]]:
                    return False
                del left_side_array[-1]
        
        return len(left_side_array) == 0
