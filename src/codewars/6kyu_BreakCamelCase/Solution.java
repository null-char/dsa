// Link: https://www.codewars.com/kata/5208f99aee097e6552000148/train/java
package src.codewars.BreakCamelCase;

class Solution {
  public static String camelCase(String input) {
    StringBuilder s = new StringBuilder();

    for (int i = 0; i < input.length(); i++) {
      char ch = input.charAt(i);

      if (Character.isUpperCase(ch)) {
        s.append(String.format(" %s", ch));
      } else {
        s.append(ch);
      }
    }

    return s.toString();
  }
}

public class Solution {
  public static void main(String[] args) {
    System.out.println(Solution.camelCase("camelCaseTest")); // Should output "camel Case Test"
    System.out.println(Solution.camelCase("camelcase")); // Should output the same input string: "camelcase"
  }
}
