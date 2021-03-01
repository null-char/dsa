// Link: https://leetcode.com/problems/shuffle-the-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> shuffle(vector<int> &nums, int n) {
    vector<int> res;

    for (int i = 0; i < n; i++) {
      res.push_back(nums.at(i));
      res.push_back(nums.at(n + i));
    }

    return res;
  }
};

int main() {
  vector<int> nums{1, 2, 3, 4, 5, 6};
  int n = 3;
  Solution soln;
  vector<int> out = soln.shuffle(nums, n);

  // Should output "1 4 2 5 3 6"
  for (int x : out) {
    cout << x << ' ';
  }
}