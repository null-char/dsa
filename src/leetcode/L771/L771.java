// Link: https://leetcode.com/problems/jewels-and-stones/
package src.leetcode.L771;

import java.util.*;

class Solution {
  public int numJewelsInStones(String jewels, String stones) {
    int numJewels = 0;

    HashMap<Character, Integer> jewelsMap = new HashMap<Character, Integer>();
    // Construct a frequency table of jewels for O(1) lookup
    for (int i = 0; i < jewels.length(); i++) {
      char jewel = jewels.charAt(i);
      jewelsMap.put(jewel, jewelsMap.getOrDefault(jewel, 0) + 1);
    }

    for (int i = 0; i < stones.length(); i++) {
      char stone = stones.charAt(i);
      if (jewelsMap.containsKey(stone)) {
        numJewels++;
      }
    }

    return numJewels;
  }
}

public class L771 {
  public static void main(String[] args) {

  }
}
