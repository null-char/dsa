// Link:
// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  TreeNode *target;
  TreeNode *ans;

 public:
  TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned,
                          TreeNode *target) {
    // Base case where we compare the node in our original tree to target. if
    // they're equal we return cloned (which will be at target since they're
    // both being traversed simultaneously)
    if (original == target || original == NULL) {
      return cloned;
    }

    // Go as deep into the left subtree as possible to try and find target.
    TreeNode *left = getTargetCopy(original->left, cloned->left, target);
    if (left != NULL) return left;

    // Couldn't find target in left subtree, so we just have the right subtree
    // to check now which should contain target.
    TreeNode *right = getTargetCopy(original->right, cloned->right, target);
    if (right != NULL) return right;

    // To not upset the compiler (technically, this will never happen since
    // target always exists)
    return nullptr;
  }
};