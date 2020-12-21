// Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
package src.leetcode.L237;

/**
 * This is such a dumb question.
 * 
 * Time Complexity: O(1)
 * 
 * Space Complexity: O(1) (Auxiliary)
 */
class Solution {
  public void deleteNode(ListNode node) {
    node.val = node.next.val;
    node.next = node.next.next;
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

class L237 {
  public static void main(String[] args) {
    ListNode head = ListNode.fromArray(new int[] { 4, 5, 1, 9 });
    Solution soln = new Solution();
    soln.deleteNode(head.next);

    head.printLinkedList();
  }
}