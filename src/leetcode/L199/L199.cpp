// Link: https://leetcode.com/problems/binary-tree-right-side-view/

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
  // I could most likely accomplish this with like way less lines of code but
  // this was the most intuitive solution that I could instantly come up with.
  // The idea is to basically have a vector of vectors representing nodes
  // associated with their depth values and since we're looking at the tree from
  // the right, all we have to do is consider the rightmost node at each depth
  // (since every node to the left of it would be occluded).
  vector<int> rightSideView(TreeNode *root) {
    vector<int> res;
    if (root == NULL) return res;

    int depth = -1;
    vector<vector<int>> depthNodes;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      depth++;
      int n = q.size();

      for (int i = 0; i < n; i++) {
        TreeNode *node = q.front();
        q.pop();

        if (depth >= depthNodes.size()) {
          depthNodes.push_back({});
        }

        depthNodes[depth].push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
    }

    for (auto nodes : depthNodes) {
      res.push_back(nodes.back());
    }

    return res;
  }
};

int main() {
  TreeNode *root = new TreeNode(1, new TreeNode(2), nullptr);
  Solution soln;
  auto res = soln.rightSideView(root);

  // Should output "1 2"
  for (int x : res) {
    cout << x << ' ';
  }
}