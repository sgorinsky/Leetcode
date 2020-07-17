def isPalindrome(x: int) -> bool:
        s = str(x)
        return s == s[::-1]
        
def isPalindromeNumber(x: int) -> bool: # purely integer solution
        if x < 0:
            return False
        
        num = x % 10
        hold = x // 10
        
        while hold > 0:
            num = num * 10 + hold % 10
            hold //= 10
        return num == x
