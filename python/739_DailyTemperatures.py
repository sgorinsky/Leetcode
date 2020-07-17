class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        stack = []
        res = [0 for i in range(len(T))]
        for i, temp in enumerate(T):
            if stack and stack[-1][0] < temp:
                while stack and stack[-1][0] < temp:
                    res[stack[-1][1]] = i-stack[-1][1]
                    del stack[-1]
            stack.append([temp, i])
        
        return res
