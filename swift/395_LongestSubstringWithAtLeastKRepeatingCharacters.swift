class Solution {
    func longestSubstring(_ s: String, _ k: Int) -> Int {
        func helper(_ start: String.Index, _ end: String.Index, _ startingPlace: Int, _ endingPlace: Int) -> Int {
            var counts = [Character : Int]()
            var idx = start
            while idx != end {
                if counts[s[idx]] == nil {
                    counts[s[idx]] = 1
                } else {
                    counts[s[idx]]! += 1
                }
                idx = s.index(after: idx)
            }
            
            idx = start
            var i = startingPlace
            while idx != end {
                if counts[s[idx]]! < k {
                    var midIdx = s.index(after: idx)
                    var mid = i + 1
                    while midIdx != end && counts[s[midIdx]]! < k {
                        midIdx = s.index(after: midIdx)
                        mid += 1
                    }
                    return max(helper(start, idx, startingPlace, i), helper(midIdx, end, mid, endingPlace))
                }
                i += 1
                idx = s.index(after: idx)
            }
            return endingPlace - startingPlace
        }
        return helper(s.startIndex, s.endIndex, 0, s.count)
    }
}
