class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        negative, divisor, dividend = (dividend < 0) != (divisor < 0), abs(divisor), abs(dividend)
        mult_count, current_mult = 0, divisor
        while current_mult <= dividend:
            current_count = 1
            while current_mult << 1 <= dividend:
                current_mult <<= 1
                current_count <<= 1
            dividend -= current_mult
            current_mult = divisor
            mult_count += current_count
        return min(2147483647, max(-mult_count if negative else mult_count, -2147483648))
