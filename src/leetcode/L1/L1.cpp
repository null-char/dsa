// Link: https://leetcode.com/problems/two-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    // Mantain a hashmap of Element -> Index for quick O(1) access.
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
      int complement = target - nums[i];
      if (m.find(complement) != m.end()) {
        return {i, m[complement]};
      }
      m.insert(make_pair(nums[i], i));
    }

    return {};
  }
};

int main() {
  vector<int> nums{3, 3};
  int target = 6;
  Solution soln;
  vector<int> res = soln.twoSum(nums, target);

  // Should output: "1 0"
  for (auto x : res) {
    cout << x << ' ';
  }
}