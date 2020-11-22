class Solution {
    func lengthOfLongestSubstringTwoDistinct(_ s: String) -> Int {
        var letterCounts = [Character : Int]()
        var currLength = 0, maxLength = 0, distinctCharCount = 0
        var trailIdx = s.startIndex
        for (idx, c) in s.enumerated() {
            currLength += 1
            letterCounts[c] = (letterCounts[c] ?? 0) + 1
            if letterCounts[c] == 1 {
                distinctCharCount += 1
            }
            while distinctCharCount > 2 {
                currLength -= 1
                letterCounts[s[trailIdx]]! -= 1
                if letterCounts[s[trailIdx]] == 0 {
                    distinctCharCount -= 1
                }
                trailIdx = s.index(after: trailIdx)
            }
            maxLength = max(maxLength, currLength)
        }
        return maxLength
    }
}
