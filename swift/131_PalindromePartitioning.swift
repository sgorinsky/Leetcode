class Solution {
    func partition(_ s: String) -> [[String]] {
        func helper(_ startIdx: String.Index, _ currentPartitions: [String]) {
            if startIdx == s.endIndex {
                palindromePartitions.append(currentPartitions)
                return
            }
            
            var idx = startIdx
            while idx != s.endIndex {
                let substring = s[startIdx...idx]
                let forward = String(substring), backward = String(substring.reversed())
                idx = s.index(after: idx)
                if forward == backward {
                    helper(idx, currentPartitions + [forward])
                }
                
            }
        }
    
        var palindromePartitions = [[String]]()
        helper(s.startIndex, [String]())
        return palindromePartitions
    }
}
