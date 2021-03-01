// Link: https://www.codewars.com/kata/51ba717bb08c1cd60f00002f/train/cpp

#include <bits/stdc++.h>
using namespace std;

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

string range_extraction(vector<int> args) {
  stringstream res;
  int i = 0;

  while (i < args.size()) {
    int x = args[i];
    if (i < args.size() - 1 && x + 1 != args[i + 1]) {
      res << x << ',';
      i++;
      continue;
    } else if (x == args.back()) {
      res << x;
      break;
    }

    int j = i + 2;
    while (j < args.size() && args[j] == x + (j - i)) {
      j++;
    }

    if (j > i + 2) {
      res << x << '-' << args[j - 1];
      if (j != args.size()) res << ',';
      i = j;
    } else {
      res << x << ',';
      i++;
    }
  }

  return res.str();
}

TEST_CASE("It extracts range", "[range_extraction]") {
  REQUIRE(range_extraction({-6, -3, -2, -1, 0,  1,  3,  4,  5,  7,
                            8,  9,  10, 11, 14, 15, 17, 18, 19, 20}) ==
          "-6,-3-1,3-5,7-11,14,15,17-20");
}