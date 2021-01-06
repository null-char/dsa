// Link: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> res;
    if (root == NULL) return res;

    int depth = -1;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      depth++;
      int n = q.size();

      for (int i = 0; i < n; i++) {
        TreeNode *node = q.front();
        q.pop();

        if (depth >= res.size()) {
          res.push_back({});
        }

        res[depth].push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
    }

    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  TreeNode *root = new TreeNode(
      3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  Solution soln;
  auto res = soln.levelOrderBottom(root);

  // Should output [[15, 7], [9, 20], [3]]
  for (vector<int> v : res) {
    cout << '[';
    for (int x : v) {
      cout << ' ' << x << ' ';
    }
    cout << ']' << ' ';
  }
}