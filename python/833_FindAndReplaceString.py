class Solution:
    def findReplaceString(self, S: str, indexes: List[int], sources: List[str], targets: List[str]) -> str:
        dict_idxs = {}
        for i, idx in enumerate(indexes):
            dict_idxs[idx] = [sources[i], targets[i]]
        
        indexes.sort()
        new, i, curr_idx = '', 0, 0
        
        while i < len(S):
            if curr_idx < len(indexes) and i == indexes[curr_idx]:
                source, target = dict_idxs[indexes[curr_idx]][0], dict_idxs[indexes[curr_idx]][1]
                if S[i:i+len(source)] == source:
                    new += target
                    i += len(source)
                else:
                    new += S[i]
                    i += 1
                curr_idx += 1 
            else:
                new += S[i]
                i += 1
                
        return new
