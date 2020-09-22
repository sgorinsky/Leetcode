class Solution {
    func inorderSuccessor(_ candidate: Node?) -> Node? {
        var node: Node? = candidate
        if node?.right != nil {
            node = node?.right
            while node?.left != nil { node = node?.left }
            return node
        }
        
        while node?.parent != nil && node?.parent?.right === node { node = node?.parent }
        return node?.parent
    }
}
