// Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/

#include <bits/stdc++.h>
using namespace std;

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
  int maxDepth(TreeNode* root) {
    if (root == NULL) {
      return 0;
    } else {
      return (1 + max(maxDepth(root->left), maxDepth(root->right)));
    }
  }

  int maxDepthBFS(TreeNode* root) {
    int depth = 0;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      depth++;

      for (int i = 0; i < q.size(); i++) {
        TreeNode* node = q.front();
        q.pop();

        if (node->right != NULL) {
          q.push(node->right);
        }
        if (node->left != NULL) {
          q.push(node->left);
        }
      }
    }

    return depth;
  }
};

int main() {
  TreeNode* root =
      new TreeNode(3, new TreeNode(5, new TreeNode(), nullptr), new TreeNode());
  Solution soln;
  cout << soln.maxDepth(root) << '\n';  // Should output 3
}