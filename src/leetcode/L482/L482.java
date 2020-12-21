// Link: https://leetcode.com/problems/license-key-formatting/
package src.leetcode.L482;

import java.util.*;

/**
 * Time Complexity: Linear work i.e O(N)
 * Space Complexity: O(N) for holding the transformed characters in a stack where N is the number of characters in the given string S.
 */
class Solution {
  public String licenseKeyFormatting(String S, int K) {
    int count = 0;
    int i = S.length() - 1;
    Stack<Character> stack = new Stack<Character>();

    while (i >= 0) {
      char ch = Character.toUpperCase(S.charAt(i));

      if (ch == '-') {
        i--;
      } else if (count == K) {
        stack.push('-');
        count = 0;
      } else {
        stack.push(ch);
        count += 1;
        i--;
      }
    }

    StringBuilder res = new StringBuilder();
    while (!stack.isEmpty()) {
      res.append(stack.pop());
    }

    return res.toString();
  }
}

class L482 {
  public static void main(String[] args) {
    // Inputs
    final String S = "2-5g-3-J";
    final int K = 2;

    Solution soln = new Solution();
    String result = soln.licenseKeyFormatting(S, K);

    System.out.println(result);
  }
}
