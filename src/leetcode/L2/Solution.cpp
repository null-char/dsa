// Link: https://leetcode.com/problems/add-two-numbers/

#include <bits/stdc++.h>
using namespace std;

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *c1 = l1->next;
    ListNode *c2 = l2->next;
    ListNode *l3 = new ListNode(l1->val + l2->val);
    int carry = getCarry(l3->val);
    l3->val = l3->val % 10;

    ListNode *c3 = l3;

    while (c1 != NULL || c2 != NULL) {
      int x = 0;

      if (c2 == NULL) {
        x = c1->val + carry;
        c3->next = new ListNode(x % 10);
        c1 = c1->next;
      } else if (c1 == NULL) {
        x = c2->val + carry;
        c3->next = new ListNode(x % 10);
        c2 = c2->next;
      } else {
        x = c1->val + c2->val + carry;
        c3->next = new ListNode(x % 10);
        c1 = c1->next;
        c2 = c2->next;
      }

      c3 = c3->next;
      carry = getCarry(x);
    }

    if (carry > 0) c3->next = new ListNode(carry);

    return l3;
  }

 private:
  int getCarry(int x) {
    if (x >= 10) {
      while (x >= 10) {
        x /= 10;
      }

      return floor(x);
    }

    return 0;
  }
};