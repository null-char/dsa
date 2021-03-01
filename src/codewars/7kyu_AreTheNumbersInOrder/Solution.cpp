// Link: https://www.codewars.com/kata/56b7f2f3f18876033f000307/train/cpp

#include <bits/stdc++.h>
using namespace std;

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

bool isAscOrder(vector<int> arr) {
  if (arr.size() < 2) return true;

  for (int i = 0; i < arr.size() - 1; i++) {
    if (arr[i] > arr[i + 1]) return false;
  }

  return true;
}

TEST_CASE("Checks if a sequence of elements are in ascending order") {
  REQUIRE(isAscOrder({1, 4, 13, 97, 508, 1047, 20058}) == true);
  REQUIRE(isAscOrder({56, 98, 123, 67, 742, 1024, 32, 90969}) == false);
}