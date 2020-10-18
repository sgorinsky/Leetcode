class Solution {
    var directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
    var ISLAND: Character = "1"
    func numIslands(_ g: [[Character]]) -> Int {
        var grid = g

        func bfs(_ row: Int, _ col: Int) {
            var head = 0
            var q = [(row, col)]
            grid[row][col] = "2"
            while head < q.count {
                let (i, j) = q[head]
                head += 1
                for direction in directions {
                    let r = i + direction[0], c = j + direction[1]
                    if canGoToNextPartOfIsland(r, c) {
                        q.append((r, c))
                        grid[r][c] = "2"
                    }
                }
            }
        }
        
        func canGoToNextPartOfIsland(_ row: Int, _ col: Int) -> Bool {
            return row >= 0 && row < grid.count && col >= 0 && col < grid[0].count && grid[row][col] == "1"
        }
        
        var count = 0
        for i in 0..<grid.count {
            for j in 0..<grid[0].count {
                if grid[i][j] == ISLAND {
                    count += 1
                    bfs(i, j)
                }
            }
        }
        return count
    }
}
