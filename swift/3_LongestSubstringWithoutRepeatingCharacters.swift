class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        var letters = [Character:Int]()
        var high = 0, idx = 0
        for (i, c) in s.enumerated() {
            if let lastLetterIdx = letters[c] {
                idx = max(lastLetterIdx + 1, idx)
            }
            letters[c] = i
            high = max(high, i - idx + 1)
        }
        return high
    }
}
