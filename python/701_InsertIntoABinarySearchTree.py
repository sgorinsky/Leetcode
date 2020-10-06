class Solution:
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        # iterative approach
        node = root
        while node:
            if node.val > val:
                if not node.left:
                    node.left = TreeNode(val)
                    return root
                node = node.left
            else:
                if not node.right:
                    node.right = TreeNode(val)
                    return root
                node = node.right
        return TreeNode(val)
