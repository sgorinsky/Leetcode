class Codec {
    func serialize(_ root: TreeNode?) -> String {
        if root == nil { return "" }
        var serializedString = "\(root?.val as! Int)"
        var stack: [TreeNode?] = [root]
        
        while !stack.isEmpty {
            var node: TreeNode? = stack.removeLast()
            if let currentNode = node {
                serializedString += " \(currentNode.left != nil ? String(currentNode.left?.val as! Int) : "N") \(currentNode.right != nil ? String(currentNode.right?.val as! Int) : "N")"
                stack.append(currentNode.right)
                stack.append(currentNode.left)
            }
        }
        return serializedString
    }
    
    func deserialize(_ data: String) -> TreeNode? {
        if data == "" { return nil }
        
        var encodedDataArrayIndex = 0
        var encodedDataArray = data.split(separator: " ")
        
        var root = TreeNode(Int(encodedDataArray[encodedDataArrayIndex]) as! Int)
        encodedDataArrayIndex += 1
        
        var stack: [TreeNode?] = [root]
        
        while !stack.isEmpty {
            var currentNode: TreeNode? = stack.removeLast()
            
            var left = encodedDataArrayIndex < encodedDataArray.count ? encodedDataArray[encodedDataArrayIndex] : "N"
            encodedDataArrayIndex += 1
            
            var right = encodedDataArrayIndex < encodedDataArray.count ? encodedDataArray[encodedDataArrayIndex] : "N"
            encodedDataArrayIndex += 1
            
            if right != "N" {
                currentNode?.right = TreeNode(Int(right) as! Int)
                stack.append(currentNode?.right)
            }
            
            if left != "N" {
                currentNode?.left = TreeNode(Int(left) as! Int)
                stack.append(currentNode?.left)
            }
        }
        return root
    }
}

// Your Codec object will be instantiated and called as such:
// var ser = Codec()
// var deser = Codec()
// deser.deserialize(ser.serialize(root))
