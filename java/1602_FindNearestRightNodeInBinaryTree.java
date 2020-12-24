class Solution {
    public TreeNode findNearestRightNode(TreeNode root, TreeNode u) {
        if (root == null) return null;
        Queue<TreeNode> q = new LinkedList<TreeNode>(){{ add(root); }};
        Queue<TreeNode> nextNodes = new LinkedList<TreeNode>(){{ add(root); }};
        while (!q.isEmpty()) {
            int sz = q.size();
            
            for (int i = 0; i < sz; ++i) {
                TreeNode node = q.poll();
                if (node == u) return q.isEmpty() ? null : q.peek();
                if (node.left != null) nextNodes.add(node.left);
                if (node.right != null) nextNodes.add(node.right);
            }
            
            while (!nextNodes.isEmpty()) q.add(nextNodes.poll());
        }
        return null;
    }
}
