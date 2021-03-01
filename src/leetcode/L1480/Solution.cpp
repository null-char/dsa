// Link: https://leetcode.com/problems/running-sum-of-1d-array/

#include <bits/stdc++.h>
using namespace std;

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

class Solution {
 public:
  vector<int> runningSum(vector<int> &nums) {
    vector<int> res;
    int sum = 0;

    for (int x : nums) {
      sum += x;
      res.push_back(sum);
    }

    return res;
  }
};

TEST_CASE("It computes the running sum", "[runningSum]") {
  Solution s;

  vector<int> nums1 = {1, 2, 3, 4};
  vector<int> r1 = {1, 3, 6, 10};
  REQUIRE(s.runningSum(nums1) == r1);
}