/**
 * Definition for a Node.
 * public class Node {
 *     public var val: Int
 *     public var neighbors: [Node?]
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.neighbors = []
 *     }
 * }
 */

class Solution {
    var clonedNodesMap = [Node? : Node?]()
    func cloneGraph(_ node: Node?) -> Node? {
        if node == nil { return nil }
        let clone: Node? = Node(node!.val)
        clonedNodesMap[node] = clone
        return dfs(node, clone)
    }
    
    func dfs(_ node: Node?, _ clone: Node?) -> Node? {
        var clone = clone
        for neighbor in node!.neighbors {
            if let clonedNeighbor = clonedNodesMap[neighbor] {
                clone!.neighbors.append(clonedNeighbor)
            } else {
                let clonedNeighbor: Node? = Node(neighbor!.val)
                clonedNodesMap[neighbor] = clonedNeighbor
                clone!.neighbors.append(clonedNeighbor)
                dfs(neighbor, clonedNeighbor)
            }
        }
        return clone
    }
}
