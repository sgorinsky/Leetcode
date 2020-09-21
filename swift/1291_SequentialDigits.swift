class Solution {
    func sequentialDigits(_ low: Int, _ high: Int) -> [Int] {
        var result: [Int] = [Int]()
        if high <= low { return result }
        
        var divisor: Int = 10, additor = 1, start = 1;
        
        // beginning of sequence for n digits of low
        while low / divisor > 0 {
            start = (start * 10) + (start % 10 + 1)
            divisor *= 10
            additor = additor * 10 + 1
        }
        
        var begin: Int = start
        
        // keep adding to begin until high
        while begin <= high {
            if begin >= low { result.append(begin) }
            begin += additor
            if begin % 10 == 0 {
                start = (start * 10) + (start % 10 + 1)
                begin = start
                additor = additor * 10 + 1
            }
        }
        return result
    }
}


