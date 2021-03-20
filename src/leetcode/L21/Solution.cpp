// Link: https://leetcode.com/problems/merge-two-sorted-lists/

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

    vector<int> toVec() {
        vector<int> res;
        ListNode *c = this;
        while (c != NULL) {
            res.push_back(c->val);
            c = c->next;
        }
        return res;
    }
};

class Solution {
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *n1 = l1;
        ListNode *n2 = l2;
        ListNode *res = new ListNode();
        ListNode *cur = res;

        while (n1 != NULL && n2 != NULL) {
            int x = min(n1->val, n2->val);
            cur->next = new ListNode(x);
            cur = cur->next;

            if (x == n1->val) {
                n1 = n1->next;
            } else {
                n2 = n2->next;
            }
        }

        if (n1 == NULL) {
            cur->next = n2;
        } else {
            cur->next = n1;
        }

        return res->next;
    }
};

TEST_CASE("Merges two sorted lists together", "[mergeTwoLists]") {
    Solution soln;

    ListNode *l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode *r1 = new ListNode(
        1, new ListNode(
               1, new ListNode(
                      2, new ListNode(3, new ListNode(4, new ListNode(4))))));
    REQUIRE(soln.mergeTwoLists(l1, l2)->toVec() == r1->toVec());
}
