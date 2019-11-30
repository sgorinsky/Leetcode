class Solution:
    def myPow(self, x: float, n: int) -> float:
        if x < -100 or x > 100 or n < -2**31 or n >= 2**31:
            return 0
        elif n == 0 or x == 1:
            return 1
        is_negative = False
        if n < 0:
            n *= -1
            is_negative = True
        product = 1
        while n != 1:
            if n%2==0:
                n /= 2
                x = x*x
            else:
                n -= 1
                product *= x
        x *= product
        return 1/x if is_negative else x
