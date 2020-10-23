class Solution {
    var closedParens: [Character : Character] = [")":"(", "}":"{", "]":"["]
    func isValid(_ s: String) -> Bool {
        var stack = [Character]()
        for c in s {
            if stack.isEmpty || closedParens[c] == nil {
                stack.append(c)
            } else {
                if closedParens[c]! == stack.last! {
                    stack.removeLast()
                } else {
                    return false
                }
            }
        }
        return stack.isEmpty
    }
}
