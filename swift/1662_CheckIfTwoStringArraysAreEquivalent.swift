class Solution {
    func arrayStringsAreEqual(_ word1: [String], _ word2: [String]) -> Bool {
        var first = 0, second = 0
        var idxA = word1[first].startIndex, idxB = word2[second].startIndex
        while first < word1.count && second < word2.count {
            while idxA != word1[first].endIndex && idxB != word2[second].endIndex {
                if word1[first][idxA] != word2[second][idxB] {
                    return false
                }
                idxA = word1[first].index(after: idxA)
                idxB = word2[second].index(after: idxB)
            }
            if idxA == word1[first].endIndex {
                first += 1
                if first < word1.count {
                    idxA = word1[first].startIndex 
                }
            }
            if idxB == word2[second].endIndex {
                second += 1
                if second < word2.count {
                    idxB = word2[second].startIndex 
                }
            }
        }
        return first == word1.count && second == word2.count
    }
}

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
