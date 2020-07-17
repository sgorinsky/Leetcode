class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        all_sets = set()
        def makePermutations(cands, current_sum, current_set):
            if current_sum == target:
                current_set.sort()
                tuplified_current_set = tuple(current_set)
                if tuplified_current_set not in all_sets:
                    result.append(current_set)
                    all_sets.add(tuplified_current_set)
            elif current_sum > target:
                return result
            else:
                for i in range(len(cands)):
                    if cands[i] > target:
                        break
                    elif i == 0 or cands[i] != cands[i-1]:
                        makePermutations(cands[:i]+cands[i+1:], current_sum+cands[i], current_set + [cands[i]])
            return result
        candidates.sort()
        return makePermutations(candidates, 0, [])
