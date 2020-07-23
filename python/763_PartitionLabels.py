class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        ranges = {}
        for i, l in enumerate(S):
            ranges[l] = [i, i] if l not in ranges else [ranges[l][0], i]
        
        ranges_list = [v for v in ranges.values()]
        ranges_list.sort(key=lambda x: x[0])
        
        res = []
        curr_range, isStart = [], True
        for [start, end] in ranges_list:
            if isStart:
                isStart = False
                curr_range = [start, end]
            elif start <= curr_range[1]:
                curr_range[1] = max(end, curr_range[1])
            else:
                res.append(curr_range)
                curr_range = [start, end]

        return [end-start+1 for [start, end] in res+[curr_range]]
