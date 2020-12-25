// Link: https://leetcode.com/problems/middle-of-the-linked-list/
package src.leetcode.L876;

class Solution {
  // We basically just have two pointers. One that traverses normally and one that
  // traverses twice as fast.
  // By the time the fast pointer reaches a dead end, the slow pointer will be at
  // the middle.
  public ListNode middleNode(ListNode head) {
    ListNode slow = head;
    ListNode fast = head;

    while (fast.next != null) {
      slow = slow.next;
      fast = fast.next.next;
    }

    return slow;
  }
}

public class L876 {
  public static void main(String[] args) {
    Solution solution = new Solution();
    ListNode ll = new ListNode(4, new ListNode(5, new ListNode(2)));
    System.out.println(solution.middleNode(ll).val);
  }
}

class ListNode {
  int val;
  ListNode next;

  ListNode() {
  }

  ListNode(int val) {
    this.val = val;
  }

  ListNode(int val, ListNode next) {
    this.val = val;
    this.next = next;
  }
}
