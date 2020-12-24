class Solution {
    func generateParenthesis(_ n: Int) -> [String] {
        func backtrack(_ currentString: String, _ left: Int, _ right: Int) {
            if currentString.count == 2 * n {
                parentheses.append(currentString)
            } else {
                if left < n {
                    backtrack(currentString + "(", left + 1, right)
                }
                
                if right < left {
                    backtrack(currentString + ")", left, right + 1)
                }
            }
        }
        
        var parentheses = [String]()
        backtrack("", 0, 0)
        return parentheses
    }
}
