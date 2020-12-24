class Solution:
    def findNearestRightNode(self, root: TreeNode, u: TreeNode) -> TreeNode:
        if not root: return root
        
        q = deque([root])
        nextnodes = deque()
        while q:
            sz = len(q)
            for i in range(sz):
                node = q.popleft()
                if node == u: return None if not q else q[0]
                if node.left: nextnodes.append(node.left)
                if node.right: nextnodes.append(node.right)
            
            while nextnodes: q.append(nextnodes.popleft())
        
        return None
