// Link: https://leetcode.com/problems/min-stack/
package L155;

import java.util.*;

/**
 * Stack which also supports retrieval of the minimum value. All operations
 * (push, pop, top and getMin) are in O(1) time.
 * 
 * Time Complexity: O(1) for all operations.
 * 
 * Space Complexity: O(N) where N is the maximum size that the stack reaches.
 */
class MinStack {
  // The currently recorded min.
  private int curMin = Integer.MAX_VALUE;
  // Internal representation of the stack. Each element is represented as a pair
  // with the second element holding the minimum value for that node.
  private Stack<Pair<Integer, Integer>> stack;

  public MinStack() {
    this.stack = new Stack<Pair<Integer, Integer>>();
    this.curMin = Integer.MAX_VALUE;
  }

  public void push(int x) {
    this.curMin = Math.min(x, this.curMin);
    this.stack.push(new Pair<Integer, Integer>(x, curMin));
  }

  public void pop() {
    this.stack.pop();

    if (!this.stack.isEmpty()) {
      this.curMin = this.stack.peek().snd();
    } else {
      this.curMin = Integer.MAX_VALUE;
    }
  }

  public int top() {
    // Simply return the last element
    return this.stack.peek().fst();
  }

  public int getMin() {
    return this.curMin;
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

class L155 {
  public static void main(String[] args) {
    MinStack minStack = new MinStack();
    minStack.push(2);
    minStack.push(0);
    minStack.push(3);
    minStack.push(0);

    System.out.println(Integer.toString(minStack.getMin())); // return 0
    minStack.pop();
    System.out.println(Integer.toString(minStack.getMin())); // return 0
    minStack.pop();
    System.out.println(Integer.toString(minStack.getMin())); // return 0
    minStack.pop();
    System.out.println(Integer.toString(minStack.getMin())); // return 2
  }
}