class Solution {
    var INT_MAX = 2147483647
    func nextGreaterElement(_ num: Int) -> Int {
        var n = num
        var digits = [Int]()
        while n > 0 {
            digits.append(n % 10)
            n /= 10
        }
        
        var switched = false
        for i in stride(from: 0, to: digits.count - 1, by: 1) {
            if digits[i] > digits[i + 1] {
                var start = 0
                switched = true
                while digits[i + 1] >= digits[start] {
                    start += 1
                }
                
                var temp = digits[i + 1]
                digits[i + 1] = digits[start]
                digits[start] = temp
                
                var idx = i, j = 0
                while j < idx {
                    var temp = digits[idx]
                    digits[idx] = digits[j]
                    digits[j] = temp
                    idx -= 1
                    j += 1
                }
                break
            }
        }
        if !switched {
            return -1
        }
        
        while !digits.isEmpty {
            if n > INT_MAX / 10 { return -1 }
            n *= 10
            n += digits.removeLast()
        }
        return n
    }
}
