// Link:
// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

#include <bits/stdc++.h>
using namespace std;

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

class Solution {
 public:
  int longestSubarray(vector<int>& nums) {
    int res = 0;
    int i = 0;
    int j = 0;
    int zeroes = 0;

    // Maintain a sliding window with at most 1 zero in it. We move the sliding window right to the next zero if the window contains more than one zero
    while (j < nums.size()) {
      if (nums[j] == 0) zeroes++;
      if (zeroes > 1) {
        while (nums[i++] != 0);
        zeroes--;
      }

      res = max(res, j - i);
      j++;
    }

    return res;
  }
};

TEST_CASE("Returns length of the longest subarray of 1's",
          "[longestSubarray]") {
  Solution s;

  vector<int> nums1 = {1, 1, 0, 1};
  REQUIRE(s.longestSubarray(nums1) == 3);
  vector<int> nums2 = {1, 1, 1};
  REQUIRE(s.longestSubarray(nums2) == 2);
  vector<int> nums3 = {1, 1, 0, 0, 1, 1, 1, 0, 1};
  REQUIRE(s.longestSubarray(nums3) == 4);
}