// Link:
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

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
    Node *node = root;
    Node *levelHead = new Node(0);

    while (node != NULL) {
      Node *needle = levelHead;

      while (node != NULL) {
        if (node->left != NULL) {
          needle->next = node->left;
          needle = needle->next;
        }
        if (node->right != NULL) {
          needle->next = node->right;
          needle = needle->next;
        }

        node = node->next;
      }

      node = levelHead->next;
      levelHead->next = nullptr;
    }

    return root;
  }
};