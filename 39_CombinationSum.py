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
