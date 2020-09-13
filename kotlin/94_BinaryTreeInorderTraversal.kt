/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class Solution {
    val nums: MutableList<Int> = mutableListOf<Int>()
    fun inorderTraversal(root: TreeNode?): List<Int> {
        if (root == null) { return nums }
        
        inorderTraversal(root?.left)
        nums.add(root?.`val`)
        inorderTraversal(root?.right)
        
        return nums
    }
}
