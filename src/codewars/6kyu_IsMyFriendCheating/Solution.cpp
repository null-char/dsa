// Link: https://www.codewars.com/kata/5547cc7dcad755e480000004/train/cpp

#include <bits/stdc++.h>
using namespace std;

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

class RemovedNumbers {
 public:
  static vector<vector<long long>> removNb(long long n) {
    vector<vector<long long>> res;
    vector<long long> elems(n);
    unordered_map<int, int> m;

    for (int i = 1; i <= n; i++) {
      m.insert(make_pair(i, 1));
      elems[i - 1] = i;
    }

    long long sum = accumulate(elems.begin(), elems.end(), 0ll);

    for (auto a : elems) {
      long long b = (sum - a) / (a + 1);
      if (a * b == sum - (a + b) && m.find(b) != m.end()) {
        res.push_back({a, b});
      }
    }

    return res;
  };
};

TEST_CASE("It identifies all possible pairs of a and b", "[remmoveNb]") {
  vector<vector<long long>> r1 = {{15, 21}, {21, 15}};
  REQUIRE(RemovedNumbers::removNb(26) == r1);
  vector<vector<long long>> r2 = {};
  REQUIRE(RemovedNumbers::removNb(100) == r2);
};