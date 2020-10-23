// Link: https://leetcode.com/problems/remove-element/

package L27;

class Solution {
  public int removeElement(int[] nums, int val) {
    int i = 0;
    for (int j = 0; j < nums.length; j++) {
      if (nums[j] != val) {
        nums[i] = nums[j];
        i++;
      }
    }
    return i;
  }
}

class L27 {
  public static void main(String[] args) {

  }
}