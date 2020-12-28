class Solution {
    func minJumps(_ arr: [Int]) -> Int {
        var N = arr.count
        var graph = [Int:[Int]]()
        for (i, n) in arr.enumerated() {
            if graph[n] != nil {
                graph[n]!.append(i)
            } else {
                graph[n] = [i]
            }
        }
        
        var count = 0
        var visited = [Bool](repeating: false, count: N)
        var nodes = [0]
        
        while !nodes.isEmpty {
            var nextNodes = [Int]()
            for node in nodes {
                if node == N - 1 {
                    return count
                }
                
                for nei in graph[arr[node]]! {
                    if !visited[nei] {
                        nextNodes.append(nei)
                        visited[nei] = true
                    }
                }
                
                for nei in [node - 1, node + 1] {
                    if nei >= 0 && nei < N && !visited[nei] {
                        nextNodes.append(nei)
                        visited[nei] = true
                    }
                }
                
                graph[node] = []
            }
            count += 1
            nodes = nextNodes
        }
        return -1
    }
}
