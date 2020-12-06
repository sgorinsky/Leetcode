from collections import deque
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return None
        
        q = deque([root])
        while q:
            size = len(q)
            for i in range(size):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                
                node.next = None if i == size - 1 else q[0]
                
        return root



class Solution:
    def connect(self, root: 'Node') -> 'Node':
        def process(child):
            nonlocal prev
            nonlocal leftmost
            if child:
                if prev:
                    prev.next = child
                else:
                    leftmost = child
                prev = child
        
        prev = leftmost = root
        while leftmost:
            curr = leftmost
            prev = leftmost = None
            while curr:
                process(curr.left)
                process(curr.right)
                curr = curr.next
        return root
