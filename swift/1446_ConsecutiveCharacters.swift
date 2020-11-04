class Solution {
    func maxPower(_ s: String) -> Int {
        if s.isEmpty { return 0 }
        var idx = s.index(s.startIndex, offsetBy: 0)
        var lastCharacter = s[idx]
        var highCount = 1, currentCount = 1
        idx = s.index(after: idx)
        while idx != s.endIndex {
            var currentCharacter = s[idx]
            if currentCharacter == lastCharacter {
                currentCount += 1
                highCount = max(highCount, currentCount)
            } else {
                currentCount = 1
                lastCharacter = currentCharacter
            }
            idx = s.index(after: idx)
        }
        return highCount
    }
}
