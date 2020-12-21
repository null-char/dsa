// Link: https://leetcode.com/problems/max-stack/
package src.leetcode.L716;

import java.util.*;

/**
 * Time Complexity: O(1) for all operations except popMax which has a time
 * complexity of O(N) where N is the number of elements - position of the max
 * node.
 * 
 * Space Complexity: O(N) where N is the maximum number of elements pushed to
 * the stack.
 */
class MaxStack {
  private int curMax = Integer.MIN_VALUE;
  Stack<Pair<Integer, Integer>> stack;

  public MaxStack() {
    this.stack = new Stack<Pair<Integer, Integer>>();
  }

  public void push(int x) {
    this.curMax = Math.max(this.curMax, x);
    this.stack.push(new Pair<Integer, Integer>(x, this.curMax));
  }

  public int pop() {
    int removed = this.stack.pop().fst();
    this.curMax = this.stack.peek().snd();

    return removed;
  }

  public int top() {
    return this.stack.peek().fst();
  }

  public int peekMax() {
    return this.curMax;
  }

  public int popMax() {
    Stack<Pair<Integer, Integer>> buf = new Stack<Pair<Integer, Integer>>();

    while (this.top() != this.curMax) {
      buf.push(this.stack.pop());
    }
    this.pop();

    while (!buf.isEmpty())
      this.stack.push(buf.pop());

    return this.peekMax();
  }
}

/**
 * Utility class for representing pair tuple data structures.
 */
class Pair<T1, T2> {
  private T1 first;
  private T2 second;

  public Pair(T1 fst, T2 snd) {
    this.first = fst;
    this.second = snd;
  }

  public T1 fst() {
    return this.first;
  }

  public T2 snd() {
    return this.second;
  }
}

class L716 {
  public static void main(String[] args) {

  }
}
