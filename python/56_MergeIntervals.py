class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals: return []
        
        sorted_intervals = sorted(intervals, key = lambda x: x[0])
        curr, merged = sorted_intervals[0], []
        for i in range(1, len(sorted_intervals)):
            if curr[1] >= sorted_intervals[i][0]:
                curr[1] = max(curr[1], sorted_intervals[i][1])
            else:
                merged.append(curr)
                curr = sorted_intervals[i]
        
        merged.append(curr)
        return merged

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals or not intervals[0]:
            return []
        
        intervals.sort(key = lambda x: x[0])

        res, curr_interval, prev_end, append_end = [], [], None, False
        for [start, end] in intervals:
            if prev_end != None and prev_end >= start:
                curr_interval = [curr_interval[0], max(curr_interval[1], end)]
            else:
                if curr_interval:
                    res.append(curr_interval)
                curr_interval = [start, end]
            
            prev_end = max(end, prev_end) if prev_end else end
            
        return res + [curr_interval]
