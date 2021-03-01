// Link: https://www.codewars.com/kata/58f5c63f1e26ecda7e000029/train/cpp

#include <bits/stdc++.h>
using namespace std;

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

vector<string> wave(string y) {
  vector<string> res;

  for (int i = 0; i < y.size(); i++) {
    if (!isspace(y[i])) {
      string yi = y;
      yi[i] = toupper(yi[i]);
      res.push_back(yi);
    }
  }

  return res;
}

TEST_CASE("It produces a mexican wave from a string", "[wave]") {
  vector<string> r1 = {"Hello", "hEllo", "heLlo", "helLo", "hellO"};
  REQUIRE(wave("hello") == r1);
  vector<string> r2 = {"Codewars", "cOdewars", "coDewars", "codEwars",
                       "codeWars", "codewArs", "codewaRs", "codewarS"};
  REQUIRE(wave("codewars") == r2);
  vector<string> r3 = {" Gap ", " gAp ", " gaP "};
  REQUIRE(wave(" gap ") == r3);
}