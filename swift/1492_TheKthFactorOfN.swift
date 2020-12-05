class Solution {
    func kthFactor(_ n: Int, _ K: Int) -> Int {
        var divisors = [Int]()
        var sqrtN = Int(sqrt(Double(n))), k = K
        for x in 1...sqrtN {
            if n % x == 0 {
                k -= 1
                divisors.append(x)
                if k == 0 {
                    return x
                }
            }
        }
        
        if sqrtN * sqrtN == n { k += 1 }
        var numDivisors = divisors.count
        return k <= numDivisors ? n / divisors[numDivisors - k] : -1
    }
}
