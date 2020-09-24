class Solution {
    func findTheDifference(_ s: String, _ t: String) -> Character {
        var letterCounts: [Character : Int] = [Character : Int]()
        
        for c in s { 
            letterCounts[c] = letterCounts[c] == nil ? 1 : letterCounts[c]! + 1
        }
        
        for c in t {
            if letterCounts[c] == nil || letterCounts[c]! == 0 {
                return c
            } else {
                letterCounts[c]! -= 1
            }
        }
        return s[s.startIndex]
    }
}
