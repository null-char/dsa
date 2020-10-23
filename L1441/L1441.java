// Link: https://leetcode.com/problems/build-an-array-with-stack-operations/submissions/
package L1441;

import java.util.*;

class Solution {
  public List<String> buildArray(int[] target, int n) {
    ArrayList<String> res = new ArrayList<String>();
    if (target.length == 0) {
      return res;
    }

    List<Integer> nums = new ArrayList<Integer>(target.length);

    for (int i = 1; i <= n; i++) {
      if (nums.size() == target.length) {
        return res;
      }

      nums.add(i);
      int idx = nums.indexOf(i);
      res.add("Push");

      if (!this.checkIfExists(i, target)) {
        nums.remove(idx);
        res.add("Pop");
      }
    }

    return res;
  }

  private boolean checkIfExists(int x, int[] arr) {
    for (int elem : arr) {
      if (elem == x)
        return true;
    }

    return false;
  }
}

class L1441 {
  public static void main(String[] args) {
    Solution soln = new Solution();
    int[] target = new int[] { 1, 2 };
    int n = 4;

    List<String> res = soln.buildArray(target, n);
    System.out.print(res);
  }
}