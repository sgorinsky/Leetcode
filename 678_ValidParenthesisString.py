class Solution(object):
    def checkValidString(self, s):
        poss_bounds = [0, 0] # [lower, upper]
        for p in s:
            poss_bounds[0] += 1 if p == '(' else -1
            poss_bounds[1] += 1 if p != ')' else -1
            
            if poss_bounds[1] < 0: break
            if poss_bounds[0] < 0: poss_bounds[0] = 0

        return poss_bounds[0] == 0
