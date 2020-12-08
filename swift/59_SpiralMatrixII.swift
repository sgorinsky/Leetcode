class Solution {
    func generateMatrix(_ n: Int) -> [[Int]] {
        var spiralMatrix = [[Int]](repeating: [Int](repeating: 0, count: n), count: n)
        var i = 0, j = 0, layer = 0, sz = n - 1
        
        for x in 1...n*n {
            if spiralMatrix[i][j] != 0 {
                layer += 1
                sz -= 1
                i = layer
                j = layer
            }
            
            spiralMatrix[i][j] = x
            
            if i == layer && j < sz { j += 1 }
            else if j == sz && i < sz { i += 1 }
            else if i == sz && j > layer { j -= 1 }
            else { i -= 1 }
        }
        return spiralMatrix
    }
}
