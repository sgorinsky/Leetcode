class Solution {
    func arrayStringsAreEqual(_ word1: [String], _ word2: [String]) -> Bool {
        var a = "", b = ""
        for word in word1 {
            for letter in word {
                a.append(letter)
            }
        }
        
        for word in word2 {
            for letter in word {
                b.append(letter)
            }
        }
        
        return a == b
    }
}
