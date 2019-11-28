def reverse(x: int) -> int:
        if x < 0:
            s = str(x)[1:] + '-'  
        else:
            s = str(x)
        n = int(s[::-1])
        if abs(n) > 2147483647:
            return 0
        else:
            return n
