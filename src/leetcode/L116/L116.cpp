// Link:
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
 public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
 public:
  Node *connect(Node *root) {
    if (root == NULL) return root;
    Node *anchor = root;

    // We are given a perfect binary tree so we just need to check that our
    // anchor still has children left
    while (anchor->left) {
      Node *cur = anchor;

      while (cur != NULL) {
        cur->left->next = cur->right;

        if (cur->next) {
          cur->right->next = cur->next->left;
        }

        cur = cur->next;
      }

      anchor = anchor->left;
    }

    return root;
  }
};