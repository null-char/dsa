// Link: https://leetcode.com/problems/linked-list-cycle/

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
  // Just a basic Floyd's algorithm (tortoise and hare)
  bool hasCycle(ListNode* head) {
    if (head == NULL || head->next == NULL) return false;

    ListNode* fast = head;
    ListNode* slow = head;

    while (fast != NULL && fast->next != NULL && slow != NULL) {
      fast = fast->next->next;
      slow = slow->next;

      if (fast == slow) return true;
    }

    return false;
  };
};

TEST_CASE("It detects a cycle in a linked list correctly", "[hasCycle]") {
  Solution s;

  ListNode* h1 =
      new ListNode(3, new ListNode(2, new ListNode(0, new ListNode(-4))));
  h1->next->next->next->next = h1->next->next;
  REQUIRE(s.hasCycle(h1) == true);

  ListNode* h2 = new ListNode(0, new ListNode(1));
  h2->next->next = h1;
  REQUIRE(s.hasCycle(h2) == true);

  ListNode* h3 = new ListNode(4, new ListNode(2, new ListNode(0)));
  REQUIRE(s.hasCycle(h3) == false);

  ListNode* h4 = new ListNode(1);
  REQUIRE(s.hasCycle(h4) == false);
};