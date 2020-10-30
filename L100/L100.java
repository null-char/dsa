// Link: https://leetcode.com/problems/same-tree/
package L100;

/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution {
  public boolean isSameTree(TreeNode p, TreeNode q) {
    if (p == null && q == null)
      return true;
    if (p == null || q == null)
      return false;
    if (p.val != q.val)
      return false;

    return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
  }
}

class TreeNode {
  int val;
  TreeNode left;
  TreeNode right;

  public TreeNode() {
  }

  public TreeNode(int val) {
    this.val = val;
  }

  public TreeNode(int val, TreeNode left, TreeNode right) {
    this.val = val;
    this.left = left;
    this.right = right;
  }
}

class Driver {
  public static void main(String[] args) {
    TreeNode p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode q = new TreeNode(1, new TreeNode(2), new TreeNode(1));

    Solution soln = new Solution();
    System.out.println(soln.isSameTree(p, q));
  }
}
