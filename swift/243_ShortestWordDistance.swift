class Solution {
    func shortestDistance(_ words: [String], _ word1: String, _ word2: String) -> Int {
        var idx = 1000000, jdx = -1000000
        var minimumDistanceBetweenWords = abs(jdx - idx)
        for (i, word) in words.enumerated() {
            if word == word1 {
                idx = i
            } else if word == word2 {
                jdx = i
            }
            
            minimumDistanceBetweenWords = min(abs(jdx - idx), minimumDistanceBetweenWords)
        }
        return minimumDistanceBetweenWords
    }
}
