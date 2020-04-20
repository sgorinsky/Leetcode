# this solution is more efficient: doesn't shift string each time but calculates cumulative shift then shifts string once
class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        total = 0
        for direction, amount in shift:
            if direction == 0:
                total += amount
            else:
                total -= amount
        
        total %= len(s)
        return s[total:] + s[:total]

# given array of two-entry arrays with [direction, amount] of string shift
# 	left when direction == 0 and right when  1 == direction
class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        length = len(s)
        for [direction, amt] in shift:
            mod_amt = amt%length
            if direction:
                s = s[length-mod_amt:] + s[:length-mod_amt]
            else:
                s = s[mod_amt:] + s[:mod_amt]
        return s
