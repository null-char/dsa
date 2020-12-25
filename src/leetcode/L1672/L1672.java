// Link: https://leetcode.com/problems/richest-customer-wealth/
package src.leetcode.L1672;

import java.util.Arrays;

class Solution {
  public int maximumWealth(int[][] accounts) {
    int maxWealth = Integer.MIN_VALUE;

    for (int[] xs : accounts) {
      int totalAmount = Arrays.stream(xs).sum();
      maxWealth = Math.max(totalAmount, maxWealth);
    }

    return maxWealth;
  }
}

public class L1672 {
  public static void main(String[] args) {
    Solution solution = new Solution();
    int[][] accounts = { { 1, 2, 3 }, { 4, 30, 1 }, { 90 } };
    System.out.println(solution.maximumWealth(accounts)); // Should print 90
  }
}
