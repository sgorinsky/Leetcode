class Solution:
    def nthUglyNumber(self, n: int) -> int:
        uglies = [1]
        cands = [uglies[-1]*2, uglies[-1]*3, uglies[-1]*5]
        indices = [0, 0, 0]
        
        while len(uglies) < n:
            curr_min = min(cands)
            if curr_min != uglies[-1]:
                uglies.append(curr_min)
            if curr_min == cands[0]:
                while uglies[indices[0]]*2 <= uglies[-1]:
                    indices[0] += 1
                cands[0] = uglies[indices[0]]*2
            elif curr_min == cands[1]:
                while uglies[indices[1]]*3 <= uglies[-1]:
                    indices[1] += 1
                cands[1] = uglies[indices[1]]*3
            else:
                while uglies[indices[2]]*5 <= uglies[-1]:
                    indices[2] += 1
                cands[2] = uglies[indices[2]]*5
        return uglies[-1]
