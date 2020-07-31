class Solution:
    def addBoldTag(self, s: str, wordDict: List[str]) -> str:
        if not s:
            return s
        
        n, word_set = len(s), set(wordDict)
        intervals = []
        last_end = 0
        for i in range(n):
            for j in range(i, n):
                if s[i:j+1] in word_set:
                    intervals.append([i, j])
                    last_end = j

        curr, merged = [], []
        for interval in intervals:
            if not curr:
                curr = interval
            elif curr[1] >= interval[0]-1:
                curr = [min(curr[0], interval[0]), max(curr[1], interval[1])]
            else:
                merged.append(curr)
                curr = interval
        
        if not (curr or merged):
            return s
        
        merged.append(curr)
        new, begin, close = '', '<b>', '</b>'
        m_idx = 0
        for i, l in enumerate(s):
            if m_idx < len(merged):
                if i == merged[m_idx][0] == merged[m_idx][1]:
                    new += begin + l + close
                    m_idx += 1
                elif i == merged[m_idx][0]:
                    new += begin + l
                elif i == merged[m_idx][1]:
                    new += l + close
                    m_idx += 1
                else:
                    new += l
            else:
                new += l
        return new
