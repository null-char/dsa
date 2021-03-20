// Link: https://leetcode.com/problems/balanced-binary-tree/

#include <bits/stdc++.h>
using namespace std;

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool isBalanced(TreeNode *root) {
    if (root == NULL)
      return true;
    int ldepth = getHeight(root->left);
    int rdepth = getHeight(root->right);

    // Subtree heights differ by more than one so we return false
    if (abs(ldepth - rdepth) > 1) {
      return false;
    } else {
      // Rule is not violated for current node so we check for the rest of the
      // subtrees.
      return isBalanced(root->left) && isBalanced(root->right);
    }
  }

private:
  // Just gets the height of a binary tree recursively
  int getHeight(TreeNode *root) {
    if (root == NULL)
      return 0;

    return (1 + max(getHeight(root->left), getHeight(root->right)));
  }
};

TEST_CASE("Checks if a tree is height balanced", "[isBalanced]") {
  Solution soln;

  TreeNode *t1 = new TreeNode(
      3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(17)));
  REQUIRE(soln.isBalanced(t1) == true);

  TreeNode *t2 = new TreeNode(
      1,
      new TreeNode(2, new TreeNode(3, new TreeNode(4), new TreeNode(4)),
                   new TreeNode(3)),
      new TreeNode(2));
  REQUIRE(soln.isBalanced(t2) == false);
}
