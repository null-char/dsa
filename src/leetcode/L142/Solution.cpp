// Link: https://leetcode.com/problems/linked-list-cycle-ii/

#include <bits/stdc++.h>
using namespace std;

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode* _next) : val(x), next(_next) {}
};

class Solution {
 public:
  ListNode* detectCycle(ListNode* head) {
    if (head == NULL || head->next == NULL) return NULL;

    ListNode* fast = head;
    ListNode* slow = head;

    while (fast != NULL && fast->next != NULL && slow != NULL) {
      fast = fast->next->next;
      slow = slow->next;

      if (fast == slow) break;
    }

    if (fast != slow) return NULL;

    slow = head;
    while (fast != slow) {
      fast = fast->next;
      slow = slow->next;
    }

    return slow;
  }
};

TEST_CASE("It detects and returns the node that starts the cycle",
          "[detectCycle]") {
  Solution s;

  ListNode* h1 =
      new ListNode(3, new ListNode(2, new ListNode(0, new ListNode(-4))));
  h1->next->next->next->next = h1->next;
  REQUIRE(s.detectCycle(h1)->val == 2);
};