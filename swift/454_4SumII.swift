class Solution {
    func fourSumCount(_ A: [Int], _ B: [Int], _ C: [Int], _ D: [Int]) -> Int {
        var sums = [Int : Int]()
        for a in A {
            for b in B {
                sums[a + b] = (sums[a + b] ?? 0) + 1
            }
        }
        
        var count  = 0
        for c in C {
            for d in D {
                count += sums[-(c + d)] ?? 0
            }
        }
        return count
    }
}
