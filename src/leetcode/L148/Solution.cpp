// Link: https://leetcode.com/problems/sort-list/

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
    // We'll do a merge sort on the linked list to achieve O(n*logn) time
    // complexity
    ListNode *sortList(ListNode *head) {
        // Base case
        if (head == NULL || head->next == NULL) {
            return head;
        }

        auto p = splitLinkedList(head);
        // Recursively sort sublists
        ListNode *a = sortList(p.first);
        ListNode *b = sortList(p.second);

        // Merge the sorted sublists
        return mergeSorted(a, b);
    }

  private:
    /// Splits a given linked list into two linked lists of almost even length
    pair<ListNode *, ListNode *> splitLinkedList(ListNode *source) {
        pair<ListNode *, ListNode *> p;
        ListNode *a;
        ListNode *b;
        ListNode *slow = source;
        ListNode *fast = source->next;

        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // Slow is before mid point
        a = source;
        b = slow->next;
        // Invalidate this pointer to NULL so that "a" (which is our front
        // portion) cuts off before "b" begins.
        slow->next = NULL;
        p.first = a;
        p.second = b;

        return p;
    }

    /// Merges two sorted linked lists
    ListNode *mergeSorted(ListNode *a, ListNode *b) {
        ListNode *res = new ListNode();
        ListNode *cur = res;
        while (a != NULL && b != NULL) {
            int x = min(a->val, b->val);
            cur->next = new ListNode(x);
            cur = cur->next;

            if (x == a->val) {
                a = a->next;
            } else {
                b = b->next;
            }
        }

        if (a == NULL) {
            cur->next = b;
        } else {
            cur->next = a;
        }

        return res->next;
    }
};

TEST_CASE("It sorts a linked list", "[sortList]") {
    Solution soln;

    ListNode *h1 =
        new ListNode(3, new ListNode(2, new ListNode(4, new ListNode(1))));
    vector<int> r1 = {1, 2, 3, 4};
    REQUIRE(soln.sortList(h1)->toVec() == r1);
}
