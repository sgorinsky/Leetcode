class Solution {
    func checkIfExist(_ arr: [Int]) -> Bool {
        var zeroes: Int = 0
        var numSet: Set<Int> = Set() // or Set.init()
        
        for n in arr {
            if n == 0 {
                zeroes += 1
            }
            numSet.update(with: n)
        }
        
        if zeroes > 1 {
            return true
        }
        
        for n in arr {
            if numSet.contains(n*2) && n != 0 {
                return true
            }
        }
        return false
    }
}
