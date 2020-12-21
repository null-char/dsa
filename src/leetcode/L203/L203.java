// Link: https://leetcode.com/problems/remove-linked-list-elements/
package src.leetcode.L203;

class Solution {
  public ListNode removeElements(ListNode head, int val) {
    // Check if the element(s) that need to be removed are at the start
    while (head != null && head.val == val) {
      head = head.next;
    }

    ListNode cur = head;
    // Ok to point prev to head since at this point we know for a fact that the
    // value to be removed is not at the start of the list.
    ListNode prev = head;

    while (cur != null) {
      if (cur.val == val) {
        prev.next = cur.next;
      } else {
        prev = cur;
      }

      cur = cur.next;
    }

    return head;
  }
}

/**
 * Singly-linked list.
 */
class ListNode {
  int val;
  ListNode next;

  public ListNode() {
  }

  public ListNode(int val) {
    this.val = val;
  }

  public ListNode(int val, ListNode next) {
    this.val = val;
    this.next = next;
  }

  /**
   * Constructs a linked list from the given array.
   * 
   * @param elems An array of ints.
   * @return The head of the linked list.
   */
  public static ListNode fromArray(int[] elems) {
    ListNode head = new ListNode();
    ListNode cur = head;

    for (int i = 0; i < elems.length; i++) {
      cur.val = elems[i];
      cur.next = (i == (elems.length - 1)) ? null : new ListNode(elems[i + 1]);
      cur = cur.next;
    }

    return head;
  }

  public void printLinkedList() {
    ListNode cur = this;

    while (cur != null) {
      System.out.println(cur.val);
      cur = cur.next;
    }

    System.out.println();
  }
}

class L203 {
  public static void main(String[] args) {
    ListNode head = ListNode.fromArray(new int[] { 1, 2, 2, 1 });
    head.printLinkedList();

    Solution soln = new Solution();
    ListNode newHead = soln.removeElements(head, 2);

    newHead.printLinkedList();
  }
}