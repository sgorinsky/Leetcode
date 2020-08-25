from collections import Counter
class Solution:
    def mincostTickets(self, days: List[int], cost: List[int]) -> int:
        last = days[-1]
        dp = [0 for _ in range(last+1)]
        travel_days = Counter(days)
        
        for i in range(last+1):
            if i not in travel_days:
                dp[i] = dp[i-1]
            else:
                one, seven, thirty = dp[max(0, i-1)] + cost[0], dp[max(0, i-7)] + cost[1], dp[max(0, i-30)] + cost[2]
                dp[i] = min(one, seven, thirty)
        
        return dp[-1]
                
            
