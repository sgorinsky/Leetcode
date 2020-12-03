class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        def inorder(node):
            if not node:
                return
            
            inorder(node.left)
            nodes.append(node)
            inorder(node.right)
        
        nodes = []
        inorder(root)
        for i, node in enumerate(nodes):
            if i < len(nodes)-1:
                node.right = nodes[i + 1]
            node.left = None
            
        return nodes[0] if nodes else None
