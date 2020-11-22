class Solution {
    var morseCodes = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
    func uniqueMorseRepresentations(_ words: [String]) -> Int {
        var uniqueWordCodes = Set<String>()
        for word in words {
            var currentWordCode = ""
            for (idx, letter) in word.enumerated() {
                let codeIdx = Int(UnicodeScalar(String(letter))!.value - UnicodeScalar("a").value)
                currentWordCode += morseCodes[codeIdx]
            }
            uniqueWordCodes.insert(currentWordCode)
        }
        return uniqueWordCodes.count
    }
}
