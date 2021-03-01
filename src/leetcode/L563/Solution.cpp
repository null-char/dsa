// Link: https://leetcode.com/problems/binary-tree-tilt/

#include <bits/stdc++.h>
using namespace std;

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int findTilt(TreeNode* root) {
    if (root == NULL) return 0;

    return abs(valueSum(root->left) - valueSum(root->right)) +
           findTilt(root->left) + findTilt(root->right);
  }

 private:
  int valueSum(TreeNode* root) {
    if (root == NULL) return 0;

    return root->val + valueSum(root->left) + valueSum(root->right);
  }
};

TEST_CASE("It computes the total tilt of a tree", "[findTilt]") {
  Solution s;
  TreeNode* r1 =
      new TreeNode(4, new TreeNode(2, new TreeNode(3), new TreeNode(5)),
                   new TreeNode(9, nullptr, new TreeNode(7)));
  REQUIRE(s.findTilt(r1) == 15);
}