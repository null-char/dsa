// Link: https://leetcode.com/problems/shortest-completing-word/
package src.leetcode.L748;

import java.util.*;

class Solution {
  public String shortestCompletingWord(String licensePlate, String[] words) {
    int minLength = Integer.MAX_VALUE;
    int idx = -1;
    String normalized = normalizeLicensePlate(licensePlate);

    for (int i = 0; i < words.length; i++) {
      String word = words[i];
      if (word.length() < minLength && doesMatch(normalized, word)) {
        minLength = word.length();
        idx = i;
      }
    }

    return words[idx];
  }

  public String normalizeLicensePlate(String lp) {
    StringBuilder sb = new StringBuilder();

    for (int i = 0; i < lp.length(); i++) {
      char ch = lp.charAt(i);

      if (ch >= 'A' && ch <= 'z') {
        sb.append(Character.toLowerCase(ch));
      }
    }

    return sb.toString();
  }

  // Checks to see if the given word matches with the license plate string given
  // the required conditions
  public Boolean doesMatch(String lp, String word) {
    if (word.length() < lp.length())
      return false;

    // Basically just a frequency counter array for all the letters in word
    int[] letters = new int[26];

    for (int i = 0; i < word.length(); i++) {
      char ch = word.charAt(i);
      letters[ch - 'a'] = letters[ch - 'a'] + 1;
    }

    for (int i = 0; i < lp.length(); i++) {
      char ch = lp.charAt(i);

      if (letters[ch - 'a'] == 0) {
        return false;
      }

      letters[ch - 'a']--;
    }

    return true;
  }
}

class SortByLength implements Comparator<String> {
  public int compare(String a, String b) {
    return a.length() - b.length();
  }
}

public class L748 {
  public static void main(String[] args) {
    String[] words = { "step", "steps", "stripe", "stepple" };
    String licensePlate = "1s3 PSt";
    Solution solution = new Solution();
    System.out.println(solution.shortestCompletingWord(licensePlate, words)); // should output "steps"
  }
}
