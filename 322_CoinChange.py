class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount < 1:
            return 0
        elif not coins:
            return -1
        
        def helper(amt, count):
            if amt < 0:
                return -1
            elif amt == 0:
                return 0
            
            if count[amt-1] != 0:
                return count[amt-1]
            
            current_min = float('inf')
            for coin in coins:
                res = helper(amt-coin, count)
                if res >= 0 and res < current_min:
                    current_min = res + 1
                
            count[amt-1] = -1 if current_min == float('inf') else current_min
            return count[amt-1]
        
        return helper(amount, [0 for i in range(amount)])
