class Solution {
    func numsSameConsecDiff(_ N: Int, _ K: Int) -> [Int] {
        var result: [Int] = [Int]()
        if N <= 1 {
            for i in 0...9 {
                result.append(i)
            }
            return result
        }
        
        var resultSet: Set<Int> = Set<Int>()
        func addNums(_ cand: Int, _ d: Int, _ count: Int) {
            if count == N {
                resultSet.insert(cand)
                return
            }
            
            if d - K >= 0 {
                addNums(cand * 10 + (d - K), d - K, count + 1)
            }
            
            if d + K <= 9 {
                addNums(cand * 10 + (d + K), d + K, count + 1)
            }
        }
        
        for i in 1...9 {
            addNums(i, i, 1)
        }
        
        for n in resultSet {
            result.append(n)
        }
        return result
    }
}
