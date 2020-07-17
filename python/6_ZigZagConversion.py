class Solution:
    def convert(self, s: str, numRows: int) -> str:    
        if not s or numRows <= 1 or numRows > len(s): return s
        
        storage = [[] for _ in range(numRows)]
        row, increasing = 0, True
        
        for l in s:
            storage[row].append(l)
            if row == len(storage)-1: increasing = False
            elif row == 0: increasing = True
                
            if increasing: row += 1
            else: row -= 1
        
        zig_zag_str = ''
        for part in storage: zig_zag_str += ''.join(part)
        
        return zig_zag_str
