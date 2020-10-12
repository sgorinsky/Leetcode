class Solution {
    func removeDuplicateLetters(_ s: String) -> String {
        var letterCounts = [Character:Int]()
        for c in s {
            letterCounts[c] = 1 + (letterCounts[c] ?? 0)
        }
        
        var stack = [Character]()
        var stackSet = Set<Character>()
        for c in s {
            if !stackSet.contains(c) {
                while !stack.isEmpty && c < stack.last! && letterCounts[stack.last!]! > 0 {
                    stackSet.remove(stack.removeLast())
                } 
                stack.append(c)
                stackSet.insert(c)
            }
            letterCounts[c] = (letterCounts[c] ?? 0) - 1
        }
        
        var result = ""
        for c in stack { result.append(c) }
        return result
    }
}
