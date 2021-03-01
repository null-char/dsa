// Link: https://www.codewars.com/kata/5592e3bd57b64d00f3000047/train/cpp

#include <bits/stdc++.h>
using namespace std;

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

class ASum {
 public:
  static long long findNb(long long m) {
    long long x = 1;
    long long n = 1;

    while (x < m) {
      n += 1;
      x += n * n * n;
    }

    if (x == m) return n;
    return -1;
  }
};

TEST_CASE("It works", "[findNB]") { REQUIRE(ASum::findNb(9) == 2); }