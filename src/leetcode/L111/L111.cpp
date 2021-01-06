// Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
  // Just a standard BFS
  int minDepth(TreeNode *root) {
    int depth = 0;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      depth++;
      int n = q.size();

      for (int i = 0; i < n; i++) {
        TreeNode *node = q.front();
        q.pop();

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);

        // Found a leaf node which means we have found the shortest path.
        if (node->left == NULL && node->right == NULL) return depth;
      }
    }

    return depth;
  }
};

int main() {
  TreeNode *root = new TreeNode(
      3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(17)));
  Solution soln;

  cout << soln.minDepth(root) << '\n';  // Should output 2
}