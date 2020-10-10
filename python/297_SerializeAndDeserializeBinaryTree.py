# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    def serialize(self, root: TreeNode) -> str:
        """Encodes a tree to a single string.
        """
        if not root:
            return ''
        
        serialized_str = f'{root.val}'
        stack = [root]
        while stack:
            curr = stack.pop()
            if curr:
                serialized_str += f' {curr.left.val}' if curr.left else ' N'
                serialized_str += f' {curr.right.val}' if curr.right else ' N'
                stack.append(curr.right)
                stack.append(curr.left)
        
        return serialized_str
                
        

    def deserialize(self, data: str) -> TreeNode:
        """Decodes your encoded data to tree.
        """
        if not data:
            return None
        
        encoded_data = deque(data.split(' '))
        root = TreeNode(encoded_data.popleft())
        stack = [root]
    
        while stack:
            curr = stack.pop()
            left = encoded_data.popleft()
            right = encoded_data.popleft() 
            
            if right != 'N':
                curr.right = TreeNode(right)
                stack.append(curr.right)
            if left != 'N':
                curr.left = TreeNode(left)
                stack.append(curr.left)
        
        return root
            
            
        
        

# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans
