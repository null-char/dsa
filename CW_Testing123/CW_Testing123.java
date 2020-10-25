// Link: https://www.codewars.com/kata/54bf85e3d5b56c7a05000cf9/train/java
package CW_Testing123;

import java.util.*;

class LineNumbering {
  public static List<String> number(List<String> lines) {
    List<String> out = new ArrayList<String>(lines.size());

    for (int i = 0; i < lines.size(); i++) {
      out.add(String.format("%d: %s", i + 1, lines.get(i)));
    }

    return out;
  }
}

class Main {
  public static void main(String[] args) {
    final List<String> lines = Arrays.asList("a", "b", "c");
    System.out.println(LineNumbering.number(lines));
  }
}
