class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        total_set = []
        def helper(cands, target, curr=[]):
            if target < 0 or len(cands) <= 0:
                return total_set
            elif target == 0:
                total_set.append(curr)
                return total_set
            else:
                helper(cands, target-cands[0], curr + [cands[0]])
                helper(cands[1:], target, curr)
            return total_set
        return helper(candidates, target, [])   

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        if candidates == []:
            return []
        d = {}
		
        for candidate in candidates:
            for i in range(1, target+1):
                if i == candidate:
                    if i not in d:
                        d[i] = [[candidate]]
                    else:
                        d[i] += [[candidate]]
						
				# see if candidate-i  exists in dicationary already
                elif i-candidate > 0 and i-candidate in d:
                    for num_set in d[i-candidate]:
						# add candidate to the saved sets in d[i-candidate]
                        x = num_set + [candidate]
                        if i not in d:
                            d[i] = [x]
                        else:
                            d[i].append(x)
        if target not in d:
            return []
        else:
            return d[target]     
