class Solution {
    public Node connect(Node root) {
        if (root == null)
            return null;
        
        Deque<Node> q = new ArrayDeque<Node>(){{
                addFirst(root);
        }};
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                Node node = q.pollFirst();
                if (node.left != null)
                    q.addLast(node.left);
                if (node.right != null)
                    q.addLast(node.right);
                
                node.next = i == size - 1 ? null : q.peekFirst();
            }
        }
        return root;
    }
}
