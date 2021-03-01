// Link: https://www.codewars.com/kata/581bb3c1c221fb8e790001ef/train/cpp

#include <bits/stdc++.h>
using namespace std;

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

vector<pair<int, int>> select_subarray(const vector<int> &arr) {
  vector<pair<int, int>> res;
  unordered_map<double, vector<pair<int, int>>> m;
  int n = arr.size();
  double fullSum = 0;
  double fullProduct = 1;
  double q = -1;

  for (auto x : arr) {
    fullSum += x;
    fullProduct *= x;
  }

  for (int i = 0; i < n; i++) {
    int num = arr[i];
    double subSum = fullSum - num;
    double subProduct = fullProduct / num;
    double subq = 0;

    if (subSum != 0)
      subq = abs(subProduct / subSum);
    else
      continue;

    if (q == -1) {
      q = subq;
    } else {
      q = min(q, subq);
    }

    if (m.find(subq) == m.end()) {
      m[subq] = {{i, num}};
    } else {
      m[subq].push_back({i, num});
    }
  }

  for (auto kv : m) {
    if (kv.first == q) return kv.second;
  }

  return {};
}

TEST_CASE("It selects the appropriate subarray", "[select_subarray]") {
  vector<pair<int, int>> r1 = {{3, -8}};
  REQUIRE(select_subarray({1, 23, 2, -8, 5}) == r1);

  vector<pair<int, int>> r2 = {{2, 23}};
  REQUIRE(select_subarray({1, 3, 23, 4, 2, -8, 5, 18}) == r2);
}