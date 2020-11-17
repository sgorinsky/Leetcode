class Solution {
    func longestMountain(_ A: [Int]) -> Int {
        if A.count < 3 { return 0 }
        
        var left = 0, right = 0, high = 0
        for i in 1..<A.count {
            if A[i] == A[i-1] {
                left = i
            } else if A[i] > A[i-1] { 
                continue
            } else {
                if i < A.count - 1 && A[i] < A[i+1] {
                    high = max(high , i - left + 1)
                    left = i
                } else {
                    right = i
                }
            }
            
            if i - 1 > left { 
                high = max(high, right - left + 1)
            } else {
                left = i
            }
        }
        return high >= 3 ? high : 0
    }
}
