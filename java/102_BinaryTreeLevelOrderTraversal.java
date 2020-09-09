class Solution {
  public List<List<Integer>> levelOrder(TreeNode root) {
      List<List<Integer>> levels = new ArrayList<List<Integer>>();
      if (root == null) return levels;
      
      Queue<TreeNode> q = new LinkedList<TreeNode>();
      q.add(root);
      int lvl = 0;
      
      while (!q.isEmpty()) {
          levels.add(new ArrayList<Integer>());
          int length = q.size();
          
          for (int i = 0; i < length; ++i) {
              TreeNode node = q.remove();
              
              levels.get(lvl).add(node.val);
              if (node.left != null) q.add(node.left);
              if (node.right != null) q.add(node.right);
          }
          ++lvl;
      }
      return levels;
  }
}
