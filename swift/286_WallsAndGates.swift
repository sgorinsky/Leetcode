class Solution {
    var directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
    var GATE = 0
    
    func wallsAndGates(_ rooms: inout [[Int]]) {
        var q = [(Int, Int)]()
        func canGoToNextRoom(_ r: Int, _ c: Int, _ i: Int, _ j: Int) -> Bool {
            return 
                r >= 0 && r < rooms.count && 
                c >= 0 &&  c < rooms[0].count && 
                rooms[r][c] > 0 && rooms[r][c] > rooms[i][j]
        }
        
        for i in 0..<rooms.count {
            for j in 0..<rooms[0].count {
                if rooms[i][j] == GATE {
                    q.append((i, j))
                }
            }
        }
        
        var head = 0
        while head < q.count {
            let (i, j) = q[head]
            head += 1
            for direction in directions {
                let r = i + direction[0], c = j + direction[1]
                if canGoToNextRoom(r, c, i, j) {
                    rooms[r][c] = min(rooms[i][j] + 1, rooms[r][c])
                    q.append((r, c))
                }
            }
        }
    }
}
