// Link: https://leetcode.com/problems/find-the-duplicate-number/
package L287;

import java.util.*;

class Solution {
  public int findDuplicate(int[] nums) {
    HashMap<Integer, Integer> seen = new HashMap<Integer, Integer>();

    for (int n : nums) {
      seen.put(n, seen.getOrDefault(n, 0) + 1);
    }

    for (Map.Entry<Integer, Integer> entry : seen.entrySet()) {
      if (entry.getValue() > 1) {
        return entry.getKey();
      }
    }

    return -1;
  }
}

class Driver {
  public static void main(String[] args) {
    int[] nums = new int[] { 1, 3, 4, 2, 2 };
    Solution soln = new Solution();
    int res = soln.findDuplicate(nums);

    System.out.println(res);
  }
}