class Solution {
    func letterCombinations(_ digits: String) -> [String] {
        if digits.isEmpty { return [String]() }
        func helper(_ start: Int, _ currentString: String, _ currentIdx: String.Index) {
            if currentString.count == digits.count {
                letterPermutations.append(currentString)
                return
            }
            
            var idx = currentIdx
            for i in start..<digits.count {
                var digit = digits[idx]
                guard let letters = digitLetterMap[digit] else { return }
                for letter in letters {
                    helper(i + 1, currentString + String(letter), digits.index(after: idx))
                }
                idx = digits.index(after: idx)
            }
        }
        
        var letterPermutations = [String]()
        var digitLetterMap: [Character : String] = ["2":"abc", "3":"def", "4":"ghi", "5":"jkl", "6":"mno", "7":"pqrs", "8":"tuv", "9":"wxyz"]
        
        helper(0, "", digits.startIndex)
        return letterPermutations
    }
}
