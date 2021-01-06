// Link: https://leetcode.com/problems/symmetric-tree/submissions/

#include <bits/stdc++.h>
using namespace std;

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
  bool isSymmetric(TreeNode *root) {
    if (root == NULL) return true;

    queue<TreeNode *> q;
    q.push(root);
    q.push(root);

    while (!q.empty()) {
      TreeNode *t1 = q.front();
      q.pop();
      TreeNode *t2 = q.front();
      q.pop();

      if (t1 == NULL && t2 == NULL) continue;
      if (t1 == NULL || t2 == NULL) return false;
      if (t1->val != t2->val) return false;

      q.push(t1->left);
      q.push(t2->right);
      q.push(t1->right);
      q.push(t2->left);
    }

    return true;
  }

  bool isSymmetricRecursive(TreeNode *root) { return isMirror(root, root); }

 private:
  bool isMirror(TreeNode *t1, TreeNode *t2) {
    if (t1 == NULL && t2 == NULL) return true;
    if (t1 == NULL || t2 == NULL) return false;

    return (t1->val == t2->val) && isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
  }
};

int main() {}