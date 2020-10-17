class Solution {
    func searchMatrix(_ matrix: [[Int]], _ target: Int) -> Bool {
        if matrix.isEmpty || matrix[0].isEmpty { return false }
        
        var rows = matrix.count, cols = matrix[0].count
        var left = 0, right = rows * cols - 1
        while left <= right {
            var mid = (left + right) >> 1
            var i = mid / cols, j = mid % cols
            
            if matrix[i][j] == target { return true }
            else if matrix[i][j] > target { right = mid - 1 }
            else { left = mid + 1 }
        }
        return false
    }
}
