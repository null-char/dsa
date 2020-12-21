// Link: https://leetcode.com/problems/design-linked-list/
package src.leetcode.L707;

import java.util.*;

class MyLinkedList {
  private Node head;
  private Node tail;
  private int length = 0;

  /** Initialize your data structure here. */
  public MyLinkedList() {
    // Dummy head and tail
    this.head = new Node(0);
    this.tail = new Node(0);
    this.head.next = this.tail;
    this.tail.prev = this.head;
  }

  /**
   * Get the value of the index-th node in the linked list. If the index is
   * invalid, return -1.
   */
  public int get(int index) {
    if (index < 0 || index >= length)
      return -1;

    Node cur = head;
    for (int i = 0; i <= index; i++) {
      cur = cur.next;
    }

    return cur.val;
  }

  /**
   * Add a node of value val before the first element of the linked list. After
   * the insertion, the new node will be the first node of the linked list.
   */
  public void addAtHead(int val) {
    addAtIndex(0, val);
  }

  /** Append a node of value val to the last element of the linked list. */
  public void addAtTail(int val) {
    addAtIndex(length, val);
  }

  /**
   * Add a node of value val before the index-th node in the linked list. If index
   * equals to the length of linked list, the node will be appended to the end of
   * linked list. If index is greater than the length, the node will not be
   * inserted.
   */
  public void addAtIndex(int index, int val) {
    if (index < 0 || index > length)
      return;

    Node cur = head;

    for (int i = 0; i < index; i++) {
      cur = cur.next;
    }

    Node newNode = new Node(val, cur.next, cur);
    cur.next.prev = newNode;
    cur.next = newNode;
    length++;
  }

  /** Delete the index-th node in the linked list, if the index is valid. */
  public void deleteAtIndex(int index) {
    if (index < 0 || index >= length)
      return;

    Node cur = head;
    for (int i = 0; i < index; i++) {
      cur = cur.next;
    }

    cur.next.next.prev = cur;
    cur.next = cur.next.next;
    length--;
  }

  public void printList() {
    StringBuilder ls = new StringBuilder();
    Node cur = head.next;

    while (cur.next != null) {
      ls.append(Integer.toString(cur.val));
      if (cur.next.next != null) {
        ls.append("->");
      }

      cur = cur.next;
    }

    System.out.println(ls.toString());
  }

  private class Node {
    int val;
    Node next;
    Node prev;

    public Node() {
    }

    public Node(int val) {
      this.val = val;
    }

    public Node(int val, Node next) {
      this.val = val;
      this.next = next;
    }

    public Node(int val, Node next, Node prev) {
      this.val = val;
      this.next = next;
      this.prev = prev;
    }
  }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList(); int param_1 = obj.get(index);
 * obj.addAtHead(val); obj.addAtTail(val); obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */

class Driver {
  public static void main(String[] args) {
    MyLinkedList myLinkedList = new MyLinkedList();
    myLinkedList.addAtHead(35);
    myLinkedList.addAtIndex(0, 69);
    myLinkedList.deleteAtIndex(1);
    myLinkedList.addAtTail(420);
    myLinkedList.addAtIndex(1, 14);
    myLinkedList.addAtTail(1337);
    myLinkedList.deleteAtIndex(1);
    myLinkedList.printList();
  }
}
