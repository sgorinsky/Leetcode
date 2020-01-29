class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        result = []
        def helper(current_list):
            if len(current_list) == k:
                result.append(current_list)
            else:
                initial = current_list[-1]+1 if len(current_list) > 0 else 1
                for i in range(initial, n+1):
                    helper(current_list+[i])
            return result
        return helper([])
