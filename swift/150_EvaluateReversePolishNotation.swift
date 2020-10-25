class Solution {
    let operations: Set = ["+", "-", "*", "/"]
    func evalRPN(_ tokens: [String]) -> Int {
        var stack = [String]()
        var a = 0, b = 0;
        var total = 0;
        
        for t in tokens {
            if operations.contains(t) {
                b = Int(stack.removeLast()) ?? 0;
                a = Int(stack.removeLast()) ?? 0;
                
                if t == "+" { total = a + b }
                else if t == "-" { total = a - b }
                else if t == "*" { total = a * b }
                else if a == 0 || b == 0 { total = 0 }
                else { total = a / b }
                
                stack.append(String(total))
            } else {
                stack.append(t)
            }
        }
        return Int(stack.removeLast()) ?? 0
    }
}
