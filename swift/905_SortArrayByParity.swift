class Solution {
    func sortArrayByParity(_ arr: [Int]) -> [Int] {
        var A: [Int] = arr
        var i = 0, j = A.count-1
        var startIdx = A.index(A.startIndex, offsetBy: 0)
        var endIdx = A.index(A.endIndex, offsetBy: -1)
        
        while i < j {
            if (A[startIdx] % 2 == 1 && A[endIdx] % 2 == 0) {
                var temp: Int = A[startIdx]
                A[startIdx] = A[endIdx]
                A[endIdx] = temp
            }
            
            if (A[startIdx] % 2 == 0) {
                i += 1
                A.formIndex(after: &startIdx)
            }
            if (A[endIdx] % 2 == 1) {
                j -= 1
                A.formIndex(before: &endIdx)
            }
        }
        return A
    }
}
