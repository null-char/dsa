// Link: https://leetcode.com/problems/missing-number/
package src.leetcode.L268;

class Solution {
  public int missingNumber(int[] nums) {
    int n = nums.length;

    return ((n * (n + 1)) / 2) - arraySum(nums);
  }

  private int arraySum(int[] nums) {
    int sum = 0;
    for (int n : nums) {
      sum += n;
    }

    return sum;
  }
}

class Driver {
  public static void main(String[] args) {
    int[] nums = new int[] { 9, 6, 4, 2, 3, 5, 7, 0, 1 };
    Solution soln = new Solution();

    int res = soln.missingNumber(nums);
    System.out.println(res);
  }
}
