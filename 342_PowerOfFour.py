class Solution:
    def isPowerOfFour(self, num):
        
        if num < 1: 
            return False
        
        elif num ==1 : 
            return True
        
        else:
            # Capture all (2^n)^k, by num & (num-1) == 0
            # Then screen out those numbers which are exact power of two only by 0xAAAAAAAA mask
            # Finally, we have number of (2^n)^k, where k >= 2
            return num & (num-1) == 0 and num & 0xAAAA_AAAA == 0

# one-liner: if n>1: checks if power of 2 and if even power of 2
class Solution:
    def isPowerOfFour(self, num):
        return num & (num-1) == 0 and num & 0xAAAA_AAAA == 0 if num > 1 else num == 1
        
