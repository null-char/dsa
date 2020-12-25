// Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
package src.leetcode.L34;

import java.util.Arrays;

class Solution {
  // We're going to do 3 binary searches. First one to get a general idea of where
  // the target is.
  // The second one will search the left array which is guaranteed to contain
  // elements less than or equal to target. This is to find the leftmost index.
  // The third one will search the right array which is guaranteed to contain
  // elements greater than or equal to target. This is to find the rightmost
  // index.

  // Total time complexity is O(3logn). The constant multiplier is negligible so
  // in the context of Big O we can reduce it down to O(logn) which is the desired
  // time complexity.
  public int[] searchRange(int[] nums, int target) {
    int n = nums.length;
    return binarySearch(nums, 0, n - 1, target);
  }

  private int[] binarySearch(int[] nums, int l, int r, int target) {
    while (r >= l) {
      int mid = l + (r - l) / 2;

      if (nums[mid] > target) {
        r = mid - 1;
      } else if (nums[mid] < target) {
        l = mid + 1;
      } else {
        // Found target. Now we're going to look for the leftmost index and rightmost
        // index.
        return new int[] { searchLeft(nums, l, mid, target), searchRight(nums, mid, r, target) };
      }
    }

    return new int[] { -1, -1 };
  }

  private int searchLeft(int[] nums, int l, int r, int target) {
    while (r > l) {
      int mid = l + (r - l) / 2;

      if (nums[mid] < target) {
        l = mid + 1;
      } else if (mid > 0 && nums[mid - 1] < target) {
        // This branch has the added implication that nums[mid] == target since no mid
        // in left array is going to be greater than target.
        return mid;
      } else {
        // nums[mid] == target and the element preceding mid is still equal to target so
        // we shorten the right boundary.
        r = mid - 1;
      }
    }

    return l;
  }

  // Pretty much the same logic from searchLeft but tweaked to find the rightmost
  // index.
  private int searchRight(int[] nums, int l, int r, int target) {
    while (r > l) {
      int mid = l + (r - l) / 2;

      if (nums[mid] > target) {
        r = mid - 1;
      } else if (mid < nums.length - 1 && nums[mid + 1] > target) {
        return mid;
      } else {
        l = mid + 1;
      }
    }

    return r;
  }
}

public class L34 {
  public static void main(String[] args) {
    int[] nums = new int[] { 5, 7, 7, 8, 8, 10 };
    int target = 8;

    Solution solution = new Solution();
    System.out.println(Arrays.toString(solution.searchRange(nums, target))); // Should output [3, 4]
  }
}
